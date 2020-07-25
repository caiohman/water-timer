#include "Buzzer.h"
#include <Arduino.h>

/*
 buzzer constructor 
 param: pin number
*/
Buzzer :: Buzzer(int pin){
  setPinNumber(pin);
}

/* 
 description: 
 param: state that is required, buzzer frequency
 return: none
   
 true = 1 (on)
 false = 0(off)
*/
void Buzzer :: activateControl(bool state, int frequency){
  state ? tone(getPinNumber() , frequency) : noTone(getPinNumber()) ;
}
