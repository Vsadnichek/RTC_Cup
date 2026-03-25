import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from geometry_msgs.msg import TwistStamped
from nav_msgs.msg import Odometry
from motion_interfaces.action import Navigate
import math
import time

class NavigationActionServer(Node):
    def __init__(self):
        super().__init__('navigation_action_server')
        
        # Action server
        self._action_server = ActionServer(
            self,
            Navigate,
            'navigate',
            self.execute_callback
        )
        
        # Publishers
        self.cmd_vel_pub = self.create_publisher(TwistStamped, '/cmd_vel', 10)
        
        # Subscribers
        self.odom_sub = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )
        
        # State variables
        self.current_x = 0.0
        self.current_y = 0.0
        self.current_yaw = 0.0
        self.odom_received = False
        
        # Configuration
        self.cell_size = 0.8  # 800 мм
        self.crossroad_tolerance = 0.03  # 3 см точность остановки
        
        # Таймер для периодического обновления (не обязательно, но полезно)
        self.timer = self.create_timer(0.1, self.timer_callback)
        
        self.get_logger().info('Navigation Action Server ready')
    
    def odom_callback(self, msg):
        """Получаем текущую позицию робота"""
        self.odom_received = True
        self.current_x = msg.pose.pose.position.x
        self.current_y = msg.pose.pose.position.y
        
        # Получаем yaw из кватерниона
        orientation = msg.pose.pose.orientation
        siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y)
        cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z)
        self.current_yaw = math.atan2(siny_cosp, cosy_cosp)
    
    def timer_callback(self):
        """Периодический callback для поддержания активности (опционально)"""
        pass
    
    def execute_callback(self, goal_handle):
        """Основной callback action-сервера"""
        command = goal_handle.request.command
        speed = goal_handle.request.speed
        
        self.get_logger().info(f'Executing command: "{command}", speed: {speed}')
        
        # Проверяем, что одометрия есть
        if not self.odom_received:
            result = Navigate.Result()
            result.success = False
            result.message = 'No odometry data received'
            goal_handle.abort()
            return result
        
        # Создаём объект для обратной связи
        feedback = Navigate.Feedback()
        
        # Выполняем соответствующую команду
        success = False
        
        try:
            if command == "forward":
                success = self.move_forward_to_crossroad(speed, feedback, goal_handle)
            elif command == "turn_left":
                success = self.turn_left_at_crossroad(speed, feedback, goal_handle)
            elif command == "turn_right":
                success = self.turn_right_at_crossroad(speed, feedback, goal_handle)
            elif command == "u_turn":
                success = self.u_turn_at_crossroad(speed, feedback, goal_handle)
            else:
                self.get_logger().error(f'Unknown command: {command}')
                result = Navigate.Result()
                result.success = False
                result.message = f'Unknown command: "{command}"'
                goal_handle.abort()
                return result
        except Exception as e:
            self.get_logger().error(f'Error during command execution: {e}')
            self.stop_robot()
            result = Navigate.Result()
            result.success = False
            result.message = f'Execution error: {e}'
            goal_handle.abort()
            return result
        
        # Формируем результат
        result = Navigate.Result()
        result.success = success
        result.message = 'Command executed successfully' if success else 'Command failed'
        
        if success:
            goal_handle.succeed()
            self.get_logger().info(f'Command "{command}" completed successfully')
        else:
            goal_handle.abort()
            self.get_logger().error(f'Command "{command}" failed')
        
        return result
    
    def move_forward_to_crossroad(self, speed, feedback, goal_handle):
        """Движение прямо до перекрёстка (800 мм)"""
        feedback.current_action = "Moving forward to crossroad"
        goal_handle.publish_feedback(feedback)
        
        start_x = self.current_x
        target_x = start_x + self.cell_size
        
        twist = TwistStamped()
        twist.header.stamp = self.get_clock().now().to_msg()
        twist.twist.linear.x = speed
        
        # Движемся до достижения цели
        # НЕ вызываем rclpy.spin_once() - одометрия обновляется в фоне
        while rclpy.ok() and abs(self.current_x - target_x) > self.crossroad_tolerance:
            self.cmd_vel_pub.publish(twist)
            
            # Обновляем прогресс
            progress = abs(self.current_x - start_x) / self.cell_size
            feedback.progress = min(progress, 1.0)
            goal_handle.publish_feedback(feedback)
            
            time.sleep(0.05)  # Просто ждём, одометрия обновляется в другом потоке
        
        # Останавливаемся
        self.stop_robot()
        feedback.progress = 1.0
        feedback.current_action = "Stopped at crossroad"
        goal_handle.publish_feedback(feedback)
        
        return True
    
    def turn_left_at_crossroad(self, speed, feedback, goal_handle):
        """Поворот налево на перекрёстке (поворот на +90°)"""
        feedback.current_action = "Turning left at crossroad"
        goal_handle.publish_feedback(feedback)
        
        target_angle = self.current_yaw + math.pi / 2  # +90°
        return self.rotate_to_angle(target_angle, speed, feedback, goal_handle)
    
    def turn_right_at_crossroad(self, speed, feedback, goal_handle):
        """Поворот направо на перекрёстке (поворот на -90°)"""
        feedback.current_action = "Turning right at crossroad"
        goal_handle.publish_feedback(feedback)
        
        target_angle = self.current_yaw - math.pi / 2  # -90°
        return self.rotate_to_angle(target_angle, speed, feedback, goal_handle)
    
    def u_turn_at_crossroad(self, speed, feedback, goal_handle):
        """Разворот на перекрёстке (поворот на 180°)"""
        feedback.current_action = "Making U-turn at crossroad"
        goal_handle.publish_feedback(feedback)
        
        target_angle = self.current_yaw + math.pi  # +180°
        return self.rotate_to_angle(target_angle, speed, feedback, goal_handle)
    
    def rotate_to_angle(self, target_angle, angular_speed, feedback, goal_handle):
        """Поворот на заданный угол"""
        initial_angle = self.current_yaw
        angle_diff = self.normalize_angle(target_angle - self.current_yaw)
        total_rotation = abs(angle_diff)
        
        if total_rotation < 0.05:
            # Уже на месте
            feedback.progress = 1.0
            goal_handle.publish_feedback(feedback)
            return True
        
        twist = TwistStamped()
        twist.header.stamp = self.get_clock().now().to_msg()
        twist.twist.angular.z = angular_speed if angle_diff > 0 else -angular_speed
        
        # Поворачиваемся
        last_angle_diff = angle_diff
        stuck_counter = 0
        
        # НЕ вызываем rclpy.spin_once() - одометрия обновляется в фоне
        while rclpy.ok() and abs(angle_diff) > 0.05:  # точность ~3°
            self.cmd_vel_pub.publish(twist)
            
            # Обновляем прогресс
            rotated = abs(last_angle_diff - angle_diff)
            if rotated < 0.01:
                stuck_counter += 1
                if stuck_counter > 50:  # Застряли (примерно 2.5 секунды)
                    self.stop_robot()
                    return False
            else:
                stuck_counter = 0
            
            feedback.progress = min(1.0 - abs(angle_diff) / total_rotation, 1.0)
            goal_handle.publish_feedback(feedback)
            
            last_angle_diff = angle_diff
            time.sleep(0.05)
            angle_diff = self.normalize_angle(target_angle - self.current_yaw)
        
        # Останавливаемся
        self.stop_robot()
        feedback.progress = 1.0
        feedback.current_action = "Turn completed"
        goal_handle.publish_feedback(feedback)
        
        return True
    
    def stop_robot(self):
        """Остановка робота"""
        twist = TwistStamped()
        twist.header.stamp = self.get_clock().now().to_msg()
        twist.twist.linear.x = 0.0
        twist.twist.angular.z = 0.0
        self.cmd_vel_pub.publish(twist)
        time.sleep(0.1)  # Даём время на остановку
    
    def normalize_angle(self, angle):
        """Нормализация угла в диапазон [-π, π]"""
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle

def main(args=None):
    rclpy.init(args=args)
    node = NavigationActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()