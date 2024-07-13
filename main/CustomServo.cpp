#include "CustomServo.h"

CustomServo::CustomServo(int servoPin, int homePos) : pin(servoPin), homePosition(homePos), currentPosition(homePos) {}

void CustomServo::attach() {
    servo.attach(pin);
}

void CustomServo::home() {
    servo.write(homePosition);
    currentPosition = homePosition;
}

void CustomServo::move(int targetAngle, int moveTime) {
    int stepCount = abs(targetAngle - currentPosition);
    int stepDelay = moveTime / stepCount;

    if (targetAngle > currentPosition) {
        for (int angle = currentPosition; angle <= targetAngle; angle++) {
            servo.write(angle);
            delay(stepDelay);
        }
    } else {
        for (int angle = currentPosition; angle >= targetAngle; angle--) {
            servo.write(angle);
            delay(stepDelay);
        }
    }

    currentPosition = targetAngle; // Update current position
}
