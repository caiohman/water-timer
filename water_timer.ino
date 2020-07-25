
#include "Buzzer.h"
#include "DigitalBasic.h"
#include "ProjectTimer.h"
/************************************************************************/

/*Global variables with pins assignments*/
//DigitalBasic *electrovalve = new DigitalBasic(6);
DigitalBasic *led_on = new DigitalBasic(7);
DigitalBasic *led_status = new DigitalBasic(8);
//DigitalBasic *bluetooth_status = new DigitalBasic();
Buzzer *buz = new Buzzer(5);



void setup() {
  // put your setup code here, to run once:

  pinMode(buz -> getPinNumber() , OUTPUT);
  //pinMode(electrovalve -> getPinNumber() , OUTPUT);
  pinMode(led_on -> getPinNumber() , OUTPUT);
  pinMode(led_status -> getPinNumber() , OUTPUT);
  //pinMode(bluetooth_status -> getPinNumber() , INPUT);
  
  Serial.begin(9600);
  Serial.println(buz -> getPinNumber());

  led_on -> stateController(1); /*arduino is working*/
}

void loop() {
  // put your main code here, to run repeatedly:
   
  
  ProjectTime *pt = new ProjectTime(10);  /*time changes with bluetooth data*/
  int tm = pt -> getTimeSelected();

  
  led_status -> stateController(1);
  //electrovalve -> stateController(0);
  pt -> waitTime((tm / 60) ? tm - 60 : tm - 1); /*for minutes and seconds*/
  buz -> activateControl(1 , 31); /* turn buzzer on*/ 
  pt -> waitTime((tm / 60) ? 60 : 1);
  buz -> activateControl(0 , 31); /* turn buzzer off*/ 
  led_status -> stateController(0);
  //electrovalve -> stateController(1); /* turn electrovalve off NA*/    

  pt -> waitTime(10);  // take off when add bluetooth
  
  delete pt;

  /*send command to disconect AT+DISC/r/n*/
  
 
}
