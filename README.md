# Arduinowiredrover
Arduino wired rover project

This project is ment to thod a little rover with camera
The rover must be wired as the it's main purpose is to look into broken copper pipe which cut signals.
The rover will have to motor that lead tread for locomotion.
It will also have two motor for a x-y direction for the camera

A controller with two joystick will give the input one joystick wil control the rover the other the camera.
Communication will be made over the TX-RX port to keep as much analog pin availible possible. 
Radio communication is off the table because most pipe material might affect negatively the signal.

To simplify as much the main code of the remote (manette.ino) and rovy(rover.ino) I made class that could be use for other purposes.

## Joystick.h

This technical text provides a detailed overview of a class-based joystick implementation that can be integrated with Arduino. The joystick class encompasses three private attributes: Arduino pins for the X-axis, Y-axis, and the press button. Additionally, four public attributes are defined for mapping the joystick values: X-axis (mapped -100 to 100), Y-axis (mapped -100 to 100), angle, and forces (mapped 0 to 100). The class also includes two essential methods: "begin" to initialize the pin mode and "update" to read analog input and update the public attributes accordingly.

### Introduction
The joystick is a popular input device used in various applications, including gaming, robotics, and remote control systems. This guide aims to provide a comprehensive understanding of a class-based joystick implementation with Arduino, allowing developers to integrate joystick functionality into their projects seamlessly.

### Joystick Class Structure
The joystick class is designed to encapsulate the joystick's behavior and provide a user-friendly interface for interaction. It consists of private and public attributes along with two essential methods.

#### 2.1 Private Attributes
The joystick class contains three private attributes:

arduino_pin_x: Represents the Arduino pin assigned to the X-axis of the joystick.
arduino_pin_y: Represents the Arduino pin assigned to the Y-axis of the joystick.
arduino_pin_press: Represents the Arduino pin assigned to the press button of the joystick.

#### 2.2 Public Attributes
The joystick class exposes four public attributes:

x: Represents the current position of the joystick on the X-axis, mapped between -100 and 100.
y: Represents the current position of the joystick on the Y-axis, mapped between -100 and 100.
angle: Represents the angle of the joystick's position with respect to the origin.
forces: Represents the force or magnitude of the joystick's position, mapped between 0 and 100.
Joystick Class Methods
The joystick class provides two essential methods that facilitate the initialization and updating of the joystick's attributes.

#### 3.1 Begin Method
The "begin" method is responsible for initializing the joystick by setting the pin modes of the Arduino pins used for the joystick's components. This method should be called once during the setup phase of the Arduino sketch.

```C++
void begin() {
    pinMode(arduino_pin_x, INPUT);
    pinMode(arduino_pin_y, INPUT);
    pinMode(arduino_pin_press, INPUT_PULLUP);
}
```
#### 3.2 Update Method
The "update" method reads the analog input values from the joystick's X-axis, Y-axis, and the press button, and updates the public attributes accordingly. This method should be called periodically in the main loop of the Arduino sketch.


### Conclusion
By implementing the joystick class described in this technical text, developers can easily integrate joystick functionality into their Arduino projects. The class's private

## MotorDriver

On the same concept of the Joystick.h, I wanted to make a class to properly take care of everything.
you declare it with the pin associated (en1, in1 in2), method begin() server te purpose of intiated the pinmode.
the method move take a forces(-100, 100) the negativity represent the opposite direction.

## Rover.h

The rover class take two MotorDriver. If you are as effective as me you can juste intialise those to motor with rover.begin()
without doing int for the motor individually. Rover as an other method call move that take a Vector (see Vector.h) and will redistribute 
the right force to give to each motor.


## transmission

This was the easiest way to handle the transmission between the two arduinos.
because i had to send 4 float and 2 bool, and i was to lazy to get the chart to do the calculation manually

## Vector.h

I remembered that in hight school i had a hard time with vector that was a direction and a forces. That's what my vector class is: angle and forces wich work perfectly with my joystick class. and transmission.




