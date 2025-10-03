import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import datetime as dt

# Define the TemperatureLogger node
class TemperatureLogger(Node):
    def __init__(self, log_file):
        super().__init__('temperature_logger')
        self.subscription = self.create_subscription(
            Float32,
            '/temperature',
            self.listener_callback,
            10)
        self.log_file = log_file

    def listener_callback(self, msg):
        current_time = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        if msg.data > 50.0:
            with open(self.log_file, 'a') as f:
                f.write(f'{current_time}    Temperature: {msg.data:.2f}°C\n')
            self.get_logger().warn('Logged temperature: %.2f' % msg.data)

def main(args=None):
    rclpy.init(args=args)

    logger = TemperatureLogger("log.txt")

    rclpy.spin(logger)

    logger.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
