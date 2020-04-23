#include <iostream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec(argv[1]);
     exec.run();
  }
  return(0);
}
