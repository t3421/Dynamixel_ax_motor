
#include "DynamixelMotor.h"

// id of the motor
//const uint8_t id=1;
// speed, between 0 and 1023
int16_t speed=512;
// communication baudrate
const long unsigned int baudrate = 1000000;

// hardware serial without tristate buffer
// see blink_led example, and adapt to your configuration
HardwareDynamixelInterface interface(Serial);

DynamixelMotor motor1(interface, 10);
DynamixelMotor motor2(interface, 20);

void setup()
{ 
  interface.begin(baudrate);
  delay(100);
  
  // check motor if no then blink LED
  uint8_t status=motor1.init();
  if(status!=DYN_STATUS_OK)
  {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    while(1);
  }

  motor1.enableTorque();  
  motor2.enableTorque();
  
  // set to joint mode, with a 180° angle range
  // see robotis doc to compute angle values
  motor1.jointMode(204, 820);
  motor1.speed(speed);
  motor2.jointMode(204, 820);
  motor2.speed(speed);
}

void loop() 
{
  motor1.goalPosition(getRandomPosition()); //Moving motor1
  delay(getRandomTime());

  motor2.goalPosition(getRandomPosition()); //Moving motor2
  delay(getRandomTime());
}

int getRandomPosition(){
  return rand() % 616 + 204; //random position from 204 to 820
}

int getRandomTime(){
  return rand() % 200 + 300; //random time from 300 to 500 ms
}
