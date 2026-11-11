# Remote-Controlled-Boat
CIJE Hackathon 2025 2nd Place - RC boat that scoops trash (ping pong balls) from a pool of water

## The challenge
- Build a boat to remove trash from water

## Features
- remote controlled
- dump truck like scooper

## Tools Used
- Arduino IDE

## How to Use
Control the boat from the joystick (up = forward, down = backwards, left = rotate left, right = rotate right, press = activate grabber)

## How it works
- Wireless Remote Control: Uses an Arduino joystick transmitter and nRF24L01 radio modules to wirelessly send directional commands (forward, backward, left, right, and diagonal movements) to the boat.
- Motorized Navigation: Uses an Arduino receiver and L298N motor driver to interpret incoming commands and independently control two motors, allowing the boat to maneuver forward, reverse, and turn.
- Servo-Powered Grabber: Integrates a servo-controlled mechanical grabber that activates when the joystick button is pressed, opening and closing to pick up and collect objects.



## Results
CIJE Hackathon 2025 - Gathered the second most balls and won 2nd place
