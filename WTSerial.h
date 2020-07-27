#ifndef WTSERIAL_H
#define WTSERIAL_H

#define TEXT_MAX 10

class WTSerial{
  private:
    char message[TEXT_MAX];
    int textLength;
  
  public:
    WTSerial(char* serialRead, int* charNumber);
    char* getMessage();
    int checksumReceived();
    
};

#endif
