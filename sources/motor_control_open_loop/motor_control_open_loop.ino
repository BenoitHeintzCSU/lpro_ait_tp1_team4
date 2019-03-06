/**
 * LPRO AIT 2019
 * TP1
 * 
 * Open Loop Motor control
 * 
 */
#include <DRV8835MotorShield.h>
#define LED_PIN 13
DRV8835MotorShield motors;
void motor_command(int command);

/**
 * setup()
 */
void setup()
{
  pinMode(LED_PIN, OUTPUT);  
  Serial.begin (9600);
}


/**
 * loop()
 */
void loop()
{
  motor_command(200);
  delay(2000);
  motor_command(-200);
  delay(2000);
}


/**
 * motor_command(int command)
 * send open loop command to motor
 * flip motor direction when command < 0
 */
void motor_command(int command)
{
  if (command < 0) {
    motors.flipM1(true);
    motors.setM1Speed(-command);
    digitalWrite(LED_PIN, LOW);
  }
  else {
    motors.flipM1(false);
    motors.setM1Speed(command);
    digitalWrite(LED_PIN, HIGH);
  }
}


