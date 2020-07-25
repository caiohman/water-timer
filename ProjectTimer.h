#ifndef PROJECTTIMER_H
#define PROJECTTIMER_H

class ProjectTime{
  private:
    int timeSelected;
  
  public:
    ProjectTime(int timeSet);
    int getTimeSelected();
    void waitTime(int timeNeeded);
};

#endif
