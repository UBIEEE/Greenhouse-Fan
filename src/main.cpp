#include <Arduino.h>
#include <Adafruit_SHT4x.h>

const int FAN_PWM_PIN = 9; // Pin for PWM control of the fan
const int TEMP_SENSOR_PIN = A0; // Pin for temperature sensor input

// FUNCTION DECLARATIONS //
int calculateFanSpeed(float temperature);
float readTemperature();

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  pinMode(FAN_PWM_PIN, OUTPUT); // Set the fan PWM pin as output
}

void loop() {
  float currentTemperature = readTemperature(); // Read the current temperature
  int pwmDutyCycle = calculateFanSpeed(currentTemperature); // Calculate the PWM duty cycle based on temperature
  analogWrite(FAN_PWM_PIN, pwmDutyCycle); // Set the PWM duty cycle

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}