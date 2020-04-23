#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

#include "leftistHeap.h"
#include "skewHeap.h"

class Executive
{
  private:
    leftistHeap* lHeap;
    skewHeap* sHeap;
    double buildLeftistTimes[5];
    double deleteLeftistTimes[5];
    double buildSkewTimes[5];
    double deleteSkewTimes[5];
    leftistHeap* buildLeftistHeap;
    leftistHeap* deleteLeftistHeap;
    skewHeap* buildSkewHeap;
    skewHeap* deleteSkewHeap;

  public:
    Executive(std::string fileName);
    ~Executive();
    void run();
    void buildLeftistTimer(int m);
    void deleteLeftistTimer(int m);
    void buildSkewTimer(int m);
    void deleteSkewTimer(int m);
    void performance();
};
#endif
