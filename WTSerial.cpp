#include <Arduino.h>
#include "WTSerial.h"

WTSerial :: WTSerial(char* serialRead, int* charNumber){
  int i;
  
  for(i = 0 ; i < *charNumber ; i++){
    message[i] = serialRead[i];
  }
  for(; i < TEXT_MAX ; i++){
    message[i] = 0;
  }
  
  textLength = *charNumber; 
}

char* WTSerial :: getMessage(){
  return message;
}

int WTSerial :: checksumReceived(){ //message is : size of message + message + checksum
  int i, sum = 0, checksum;

  int messageSize = message[0] - '0';
  
  for(i = 1 ; i <= messageSize  ; i++){ 
    sum += (int)message[i];
  }

  checksum = ~sum;

  return checksum;   
}
