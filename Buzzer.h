#ifndef BUZZER_H
#define BUZZER_H
#include "Control.h"

class Buzzer : public Control {
  public:
    Buzzer(int pin);
    void activateControl(bool state, int frequency);
};

#endif
