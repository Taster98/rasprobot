from gpiozero import Robot
from signal import pause
import time
robot = Robot(left = (8, 7), right = (9, 10))

while True:
	robot.forward()
