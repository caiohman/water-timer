
#include "Buzzer.h"
#include "DigitalBasic.h"
#include "ProjectTime.h"
#include "WTSerial.h"

/************************************************************************/
             /*Global variables with pins assignments*/
//DigitalBasic *electrovalve = new DigitalBasic(6);
//DigitalBasic *bluetooth_status = new DigitalBasic();
//Buzzer *buz = new Buzzer(5);
DigitalBasic *led_on = new DigitalBasic(7);
DigitalBasic *led_status = new DigitalBasic(8);
/************************************************************************/

void setup() {
  //put your setup code here, to run once:

  //pinMode(buz -> getPinNumber() , OUTPUT);
  //pinMode(electrovalve -> getPinNumber() , OUTPUT);
  //pinMode(bluetooth_status -> getPinNumber() , INPUT);
  pinMode(led_on -> getPinNumber() , OUTPUT);
  pinMode(led_status -> getPinNumber() , OUTPUT);

  Serial.begin(9600);
  
  led_on -> stateController(1); /*arduino is working*/
}

void loop() {
  // put your main code here, to run repeatedly:

  led_status -> stateController(0); /* green led */

  int bytesNumber = 0, i = 0;
   
  while(!Serial.available()); //lock
  
  delay(100);/* wait message */
   
  bytesNumber = Serial.available(); 
  
  char message[bytesNumber];
  
  for( ; i < bytesNumber ; i++){
    message[i] = Serial.read();  
  }
  
  WTSerial *data = new WTSerial(message , &bytesNumber);
  
  Serial.write(data -> getMessage());

  ProjectTime *pt = new ProjectTime(10);  /* time changes with bluetooth data */
  int tm = pt -> getTimeSelected();

  //electrovalve -> stateController(0);
  pt -> waitTime((tm / 60) ? tm - 60 : tm - 1); /* for minutes and seconds */
  //buz -> activateControl(1 , 31); /* turn buzzer on */ 
  pt -> waitTime((tm / 60) ? 60 : 1);
  //buz -> activateControl(0 , 31); /* turn buzzer off */ 
  led_status -> stateController(1); /* red led */
  //electrovalve -> stateController(1); /* turn electrovalve off NA*/    

  pt -> waitTime(10);  // take off when add bluetooth
  
  delete pt;
  delete data;

  /*send command to disconect AT+DISC/r/n*/
}
