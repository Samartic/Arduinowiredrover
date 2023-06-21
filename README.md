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

This librairy contain the class of a joystick as i wish it to exist. 
to declare one you simply put the pin of the axis and the press button.
The begin() method must be use in the void setup() section to intiate the joystick or 
if you prefer declare the pinMode as input. in the void loop() section you have to use the update() 
method to make sure to get a valid reading. then you can acces a bunch of different information:

x : value on X axis already map
y : value on Y axis already map
angle : get an angle from y=0 positive with a p(x,y) passing throught origine.
forces: get the force 0 to 100

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




