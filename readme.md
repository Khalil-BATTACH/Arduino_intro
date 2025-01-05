# README: Line-Following Robot with Arduino

This project demonstrates how to build and program a simple line-following robot using an Arduino. The robot uses two IR sensors to detect a black line on the ground and two DC motors to move along the line.

---

## Components Required

- **Arduino Uno** (or compatible board)
- **2 IR sensors** (for line detection)
- **2 DC motors** (with wheels)
- **Motor driver module** (e.g., L298N)
- **Chassis** (to build the robot)
- **Black tape or a printed line** (for the robot to follow)
- **Power supply** (e.g., 9V battery or battery pack)
- **Jumper wires** (for connections)

---

## Circuit Diagram

1. **IR Sensors**:
   - Connect the left IR sensor to analog pin `A0`.
   - Connect the right IR sensor to analog pin `A1`.
   - Connect the `VCC` of both sensors to `5V` on the Arduino.
   - Connect the `GND` of both sensors to `GND` on the Arduino.

2. **Motor Driver**:
   - Connect the left motor to output pins `2` and `3` on the Arduino.
   - Connect the right motor to output pins `4` and `5` on the Arduino.
   - Connect the motor driver's `VCC` and `GND` to the power supply and Arduino `GND`.
   - Connect the motor driver's input pins to the Arduino as per the code.

3. **Power Supply**:
   - Ensure the Arduino and motors are powered appropriately. Use a separate power source for the motors if necessary.

---

## How to Use the Code

1. **Download the Code**:
   - Copy the code from `line_follower_robot.ino` or download the file.

2. **Open Arduino IDE**:
   - Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/) if you haven't already.

3. **Upload the Code**:
   - Connect your Arduino to your computer via USB.
   - Open the `line_follower_robot.ino` file in the Arduino IDE.
   - Select the correct board and port under `Tools` > `Board` and `Tools` > `Port`.
   - Click the `Upload` button (right arrow icon) to upload the code to the Arduino.

4. **Calibrate the Sensors**:
   - Place the robot on the line and open the `Serial Monitor` (`Ctrl+Shift+M`).
   - Observe the sensor values printed on the screen.
   - Adjust the `sensorThreshold` value in the code if necessary to ensure accurate line detection.

5. **Test the Robot**:
   - Place the robot on a surface with a black line.
   - Power the robot and watch it follow the line.

---

## Code Overview

- **Sensors**:
  - The IR sensors detect the line by measuring reflected light. A low value indicates the line is detected.

- **Motors**:
  - The motors are controlled using the motor driver. The robot moves forward, turns left, or turns right based on the sensor inputs.

- **Logic**:
  - If both sensors detect the line, the robot moves forward.
  - If only the left sensor detects the line, the robot turns left.
  - If only the right sensor detects the line, the robot turns right.
  - If no line is detected, the robot stops.

---

## Troubleshooting

- **Robot doesn't move**:
  - Check motor connections and ensure the motor driver is powered.
  - Verify the sensor values using the Serial Monitor.

- **Robot doesn't follow the line accurately**:
  - Adjust the `sensorThreshold` value in the code.
  - Ensure the sensors are properly aligned with the line.

- **Motors behave erratically**:
  - Double-check the motor driver connections.
  - Ensure the power supply is sufficient for the motors.

---

## Customization

- Add more sensors for better accuracy.
- Implement speed control using PWM.
- Add Bluetooth or Wi-Fi for remote control.

---
