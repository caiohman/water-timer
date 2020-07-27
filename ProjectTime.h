#ifndef PROJECTTIME_H
#define PROJECTTIME_H

class ProjectTime{
  private:
    int timeSelected;
  
  public:
    ProjectTime(int timeSet);
    int getTimeSelected();
    void waitTime(int timeNeeded);
};

#endif
