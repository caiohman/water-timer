class Control{

  private:
    int controlledPin;  //virtual make it abstract
 
  public:
    void setPinNumber(int pin);
    int getPinNumber();
};

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

/************************************************************************/

class Buzzer : public Control {
  public:
    Buzzer(int pin);
    void activateControl(bool state, int frequency);
};

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

/************************************************************************/

class DigitalBasic : public Control {
  public:
    DigitalBasic(int pin);
    void stateController(bool state);
};


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

/************************************************************************/

class ProjectTime{
  private:
    int timeSelected;
  
  public:
    ProjectTime(int timeSet);
    int getTimeSelected();
    void waitTime(int timeNeeded);
};

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
