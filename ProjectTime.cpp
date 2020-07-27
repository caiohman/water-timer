#include <Arduino.h>
#include "ProjectTime.h"

/*
 project_time constructor 
 param: time received by bluetooth
*/
ProjectTime :: ProjectTime(int timeSet){
  timeSelected = timeSet;
}

/* 
 description: get time delay value
 param: none
 return: delay time in seconds
*/
int ProjectTime :: getTimeSelected(){
  return timeSelected;
}

/* 
 description: set delay
 param: none
 return: none
*/
void ProjectTime :: waitTime(int timeNeeded){
  int i;
  for( i = 0 ; i < timeNeeded ; i++){
    delay(1000);  
  } 
}
