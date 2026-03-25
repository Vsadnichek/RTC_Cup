import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from motion_interfaces.action import Navigate
import time

class TestNavigation(Node):
    def __init__(self):
        super().__init__('test_navigation')
        self.action_client = ActionClient(self, Navigate, 'navigate')
        self.get_logger().info('Test navigation node created')
    
    def send_command(self, command, speed=0.2):
        """Отправка команды в action-сервер"""
        self.get_logger().info(f'Sending command: {command} at {speed} m/s')
        
        # Ждём сервер
        if not self.action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('Action server not available')
            return False
        
        # Создаём цель
        goal_msg = Navigate.Goal()
        goal_msg.command = command
        goal_msg.speed = speed
        
        # Отправляем цель
        future = self.action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, future)
        
        goal_handle = future.result()
        
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected')
            return False
        
        # Ждём результат
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        
        result = result_future.result()
        if result.result.success:
            self.get_logger().info(f'Command {command} completed: {result.result.message}')
            return True
        else:
            self.get_logger().error(f'Command {command} failed: {result.result.message}')
            return False
    
    def test_route(self):
        """Тестовый маршрут"""
        route = [
            ("forward", 0.2),
            ("forward", 0.2),
            ("turn_left", 0.3),
            ("forward", 0.2),
            ("turn_right", 0.3),
            ("forward", 0.2),
            ("u_turn", 0.2),
        ]
        
        for command, speed in route:
            success = self.send_command(command, speed)
            if not success:
                self.get_logger().error('Route execution failed')
                return False
            time.sleep(1)  # Пауза между командами
        
        self.get_logger().info('Route completed successfully')
        return True

def main(args=None):
    rclpy.init(args=args)
    node = TestNavigation()
    
    # Ждём немного для инициализации
    time.sleep(2)
    
    # Выполняем тестовый маршрут
    node.test_route()
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()