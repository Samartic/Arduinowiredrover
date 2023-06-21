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

#### Private Attributes
The joystick class contains three private attributes:

arduino_pin_x: Represents the Arduino pin assigned to the X-axis of the joystick.
arduino_pin_y: Represents the Arduino pin assigned to the Y-axis of the joystick.
arduino_pin_press: Represents the Arduino pin assigned to the press button of the joystick.

#### Public Attributes
The joystick class exposes four public attributes:

x: Represents the current position of the joystick on the X-axis, mapped between -100 and 100.
y: Represents the current position of the joystick on the Y-axis, mapped between -100 and 100.
angle: Represents the angle of the joystick's position with respect to the origin.
forces: Represents the force or magnitude of the joystick's position, mapped between 0 and 100.
Joystick Class Methods
The joystick class provides two essential methods that facilitate the initialization and updating of the joystick's attributes.

#### Begin Method
The "begin" method is responsible for initializing the joystick by setting the pin modes of the Arduino pins used for the joystick's components. This method should be called once during the setup phase of the Arduino sketch.

```C++
void begin() {
    pinMode(arduino_pin_x, INPUT);
    pinMode(arduino_pin_y, INPUT);
    pinMode(arduino_pin_press, INPUT_PULLUP);
}
```
#### Update Method
The "update" method reads the analog input values from the joystick's X-axis, Y-axis, and the press button, and updates the public attributes accordingly. This method should be called periodically in the main loop of the Arduino sketch.


### Conclusion

By implementing the joystick class described in this technical text, developers can easily integrate joystick functionality into their Arduino projects. The class's private

## MotorDriver

This technical text presents the MotorDriver class, designed to handle motor control operations efficiently. The class incorporates private attributes for three pins: EN1 (Enable Pin), IN1 (Input Pin 1), and IN2 (Input Pin 2). It also provides two essential methods: "begin" for initializing the pin mode and "move" for controlling the motor's movement based on a provided force value (-100 to 100), where negativity represents the opposite direction.

### Introduction

The MotorDriver class aims to simplify motor control operations by encapsulating the necessary functionality into a single class. This guide explores the structure and usage of the MotorDriver class, which enables developers to control motors with ease, considering the forces (-100 to 100).

### MotorDriver Class Structure
The MotorDriver class consists of private attributes and two essential methods for motor control.

#### Private Attributes
The MotorDriver class incorporates three private attributes:
- en1_pin: Represents the Arduino pin associated with the motor's enable pin (EN1).
- in1_pin: Represents the Arduino pin associated with the motor's input pin 1 (IN1).
- in2_pin: Represents the Arduino pin associated with the motor's input pin 2 (IN2).

#### Public Methods
The MotorDriver class provides two public methods:
- begin(): Initializes the MotorDriver by setting the pin modes of the associated Arduino pins.
- move(int force): Controls the motor's movement based on the provided force value, where negativity represents the opposite direction.

### MotorDriver Class Methods
The MotorDriver class includes two crucial methods for initializing the pin mode and controlling the motor's movement.

#### begin() Method
The "begin" method initializes the MotorDriver by setting the pin modes for the associated Arduino pins (EN1, IN1, IN2). This method should be called once during the setup phase of the Arduino sketch.

```c++
void begin() {
    pinMode(en1_pin, OUTPUT);
    pinMode(in1_pin, OUTPUT);
    pinMode(in2_pin, OUTPUT);
}
```

#### move(int force) Method
The "move" method controls the motor's movement based on the provided force value. The force value ranges from -100 to 100, where negativity represents the opposite direction. A positive force value rotates the motor in one direction, while a negative force value rotates it in the opposite direction. The absolute value of the force represents the intensity of the motor's movement.

Pseudocode:
```c++
void move(int force) {
    // Determine the direction based on the sign of the force value
    if (force > 0) {
        digitalWrite(in1_pin, HIGH);
        digitalWrite(in2_pin, LOW);
    } else if (force < 0) {
        digitalWrite(in1_pin, LOW);
        digitalWrite(in2_pin, HIGH);
    } else {
        // If force is zero, stop the motor
        digitalWrite(in1_pin, LOW);
        digitalWrite(in2_pin, LOW);
        return;
    }

    // Map the force value from the range -100 to 100 to the range 0 to 255 for analogWrite
    int speed = map(abs(force), 0, 100, 0, 255);
    analogWrite(en1_pin, speed);
}
```

### Conclusion
By utilizing the MotorDriver class as outlined in this technical text, developers can effectively control motors with ease. The class encapsulates the motor control operations, including pin initialization and movement control based on force values. With this class, developers can integrate motor control into their Arduino projects effortlessly.

## Rover.h

This technical text presents the Rover class, designed to control a robotic rover using two MotorDriver instances. The Rover class encapsulates the functionality of two motors, utilizing the MotorDriver class. The class provides a simplified interface for initialization and movement control using a vector representation. The movement vector determines the forces to be distributed between the two motors, allowing precise rover control.

### Introduction
The Rover class is designed to facilitate the control of a robotic rover by encapsulating the functionality of two motors using instances of the MotorDriver class. This guide explains the structure and usage of the Rover class, allowing developers to easily initialize and control the movement of the rover using a vector representation.

### Rover Class Structure
The Rover class comprises private attributes, a begin() method for initialization, and a move() method for controlling the rover's movement.

#### Private Attributes
The Rover class incorporates the following private attribute:
- motor1: Represents the first MotorDriver instance associated with one of the rover's motors.
- motor2: Represents the second MotorDriver instance associated with the other rover motor.

#### Public Methods
The Rover class provides two public methods:
- begin(): Initializes both motors simultaneously by calling the begin() method of the MotorDriver instances.
- move(Vector forceVector): Controls the rover's movement based on the provided force vector, distributing the appropriate forces to each motor.

### Rover Class Methods
The Rover class includes two crucial methods for initialization and controlling the rover's movement.

#### begin() Method
The "begin" method initializes both motors simultaneously by calling the begin() method of each MotorDriver instance (motor1 and motor2). This method should be called once during the setup phase of the Arduino sketch.

```C++
void begin() {
    motor1.begin();
    motor2.begin();
}
```

#### move(Vector forceVector) Method
The "move" method controls the rover's movement based on the provided force vector. The force vector, represented by an instance of the Vector class, contains the forces to be distributed between the two motors. The forces will be redistributed to ensure precise rover control. Remember that a vector as an angle and a forces.



### Conclusion
The Rover class presented in this technical text simplifies the control of a robotic rover using two MotorDriver instances. By encapsulating motor functionality and providing an intuitive interface, developers can easily initialize the rover and control its movement using a vector representation. Incorporating the Rover class into Arduino projects enables efficient and precise rover control.


## transmission

This was the easiest way to handle the transmission between the two arduinos.
because i had to send 4 float and 2 bool, and i was to lazy to get the chart to do the calculation manually

## Vector.h

I remembered that in hight school i had a hard time with vector that was a direction and a forces. That's what my vector class is: angle and forces wich work perfectly with my joystick class. and transmission.




