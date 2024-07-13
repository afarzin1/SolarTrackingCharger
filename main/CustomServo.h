#ifndef CUSTOMSERVO_H
#define CUSTOMSERVO_H

#include <Arduino.h>
#include <Servo.h>

class CustomServo {
private:
    Servo servo;
    int pin;
    int homePosition;
    int currentPosition;

public:
    // Constructor to initialize servo pin and home position
    CustomServo(int servoPin, int homePos);

    // Attach the servo to the specified pin
    void attach();

    // Move the servo to its home position
    void home();

    // Move the servo to the specified angle over the specified time (in milliseconds)
    void move(int targetAngle, int moveTime);
};

#endif
