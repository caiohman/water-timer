#ifndef DIGITALBASIC_H
#define DIGITALBASIC_H
#include "Control.h" 

class DigitalBasic : public Control {

  public:
    DigitalBasic(int pin);
    void stateController(bool state);
};

#endif
