#ifndef CONTROL_H
#define CONTROL_H

class Control{

  private:
    int controlledPin;  //virtual make it abstract
 
  public:
    void setPinNumber(int pin);
    int getPinNumber();
};

#endif
