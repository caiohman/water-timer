#include "DigitalBasic.h"
#include <Arduino.h>
/*
 digital function control constructor 
 param: pin number
*/
DigitalBasic :: DigitalBasic(int pin){
  setPinNumber(pin);
}
/* 
 description: Set digital output value
 param: state that is required
 return: none
   
 true = 1 (on)
 false = 0(off)
*/
void DigitalBasic :: stateController(bool state){
 state ?  digitalWrite(getPinNumber() , HIGH) : digitalWrite(getPinNumber() , LOW);
}
