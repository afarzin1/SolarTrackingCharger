#include <Arduino.h>
#include <mbed.h>
#include <chrono>

// Declare tasks
void TaskMain(void);
void TaskServoPan(void);
void TaskServoTilt(void);

// Create event queues and threads for the tasks
rtos::Thread threadMain;
rtos::Thread threadServoPan;
rtos::Thread threadServoTilt;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Start tasks in separate threads
  threadMain.start(TaskMain);
  threadServoPan.start(TaskServoPan);
  threadServoTilt.start(TaskServoTilt);
}

void loop() {
  // The loop function will not be used since RTOS handles the tasks
}

void TaskMain() {
  while (true) {
    Serial.println("Main Task Running");
    rtos::ThisThread::sleep_for(std::chrono::milliseconds(1000));  // Delay for 1 second
  }
}

void TaskServoPan() {
  while (true) {
    Serial.println("Servo Pan Task Running");
    rtos::ThisThread::sleep_for(std::chrono::milliseconds(1000));  // Delay for 1 second
  }
}

void TaskServoTilt() {
  while (true) {
    Serial.println("Servo Tilt Task Running");
    rtos::ThisThread::sleep_for(std::chrono::milliseconds(1000));  // Delay for 1 second
  }
}
