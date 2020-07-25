#include "Control.h"

/* 
 description: get buzzer pin value
 param: none
 return: buzzer pin number
*/
int Control :: getPinNumber(){
  return controlledPin;
}

/* 
 description: set buzzer pin value
 param: none
 return: buzzer pin number
*/
void Control :: setPinNumber(int pin){
  controlledPin = pin;
}
