#include "Executive.h"

Executive::Executive(std::string fileName)
{
  lHeap= new leftistHeap();
  sHeap= new skewHeap();
  buildLeftistHeap= new leftistHeap();
  deleteLeftistHeap = new leftistHeap();
  buildSkewHeap = new skewHeap();
  deleteSkewHeap = new skewHeap();
  std::ifstream inFile(fileName);
  int entry;
  while(inFile>>entry)
  {
    lHeap->insert(entry);
    sHeap->insert(entry);
  }
}

Executive::~Executive()
{

}

void Executive::run()
{
  std::cout<<"WELCOME TO JUSTN'S LAB 9\n";
  int choice= -1;
  while(choice != 6)
  {
    std::cout<<"Pick an option:\n1.Test build- leftist heap\n2.Test deleteMin- leftist heap\n3.Test build- skew heap\n4.Test deleteMin- skew heap\n5.Test performance of heaps\n6. Exit\n\nChoose an option: ";
    std::cin>>choice;
    if(choice == 1)
    {
      lHeap->print();
      std::cout<<"\n\n";
    }
    else if(choice == 2)
    {
      lHeap->deleteMin();
      lHeap->print();
      std::cout<<"\n\n";
    }
    else if(choice == 3)
    {
      sHeap->print();
      std::cout<<"\n\n";
    }
    else if(choice == 4)
    {
      sHeap->deleteMin();
      sHeap->print();
      std::cout<<"\n\n";
    }
    else if(choice == 5)
    {
      performance();
    }
    else if(choice == 6)
    {
      std::cout<<"Exiting....\n\n";
    }
    else
    {
      std::cout<<"Invalid input. (must be between 1-6)\n\n";
    }
  }
}

void Executive::buildLeftistTimer(int m)
{
  clock_t start, finish;
  start = clock();
  for(int i= 1; i< 100000 * m; i++)
  {
    int value = 0;
    value = (rand() % 5000000 + 1);
    buildLeftistHeap->insert(value);
  }
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  buildLeftistTimes[m-1] = time;
}

void Executive::deleteLeftistTimer(int m)
{
  clock_t start, finish;
  for(int i= 1; i< 100000 * m; i++)
  {
    int value = 0;
    value = (rand() % 5000000 + 1);
    deleteLeftistHeap->insert(value);
  }
  start = clock();
  deleteLeftistHeap->deleteMin();
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  deleteLeftistTimes[m-1] = time;
}

void Executive::buildSkewTimer(int m)
{
  clock_t start, finish;
  start = clock();
  for(int i= 1; i< 100000 * m; i++)
  {
    int value = 0;
    value = (rand() % 5000000 + 1);
    buildSkewHeap->insert(value);
  }
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  buildSkewTimes[m-1] = time;
}

void Executive::deleteSkewTimer(int m)
{
  clock_t start, finish;
  for(int i= 1; i< 100000 * m; i++)
  {
    int value = 0;
    value = (rand() % 5000000 + 1);
    deleteSkewHeap->insert(value);
  }
  start = clock();
  deleteSkewHeap->deleteMin();
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  deleteSkewTimes[m-1] = time;
}

void Executive::performance()
{
  for(int i = 1; i < 6; i ++)
  {
    buildLeftistTimer(i);
    deleteLeftistTimer(i);
    buildSkewTimer(i);
    deleteSkewTimer(i);
  }
  std::cout<<"_______________________LEFTIST HEAP_________________________\n";
  std::cout<<"Input size ";
  for(int i = 1; i < 6; i++)
  {
    std::cout<<100000*i<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Builds ";
  for(int i = 0; i < 5; i++)
  {
    std::cout<<buildLeftistTimes[i]<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Delete mins ";
  for(int i = 0; i < 5; i++)
  {
    std::cout<<buildLeftistTimes[i]<<" ";
  }
  std::cout<<std::endl;
  std::cout<<std::endl<<std::endl;
  std::cout<<"___________________________SKEW HEAP____________________________\n";
  std::cout<<"Input size ";
  for(int i=1; i < 6; i++)
  {
    std::cout<<100000*i<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Builds ";
  for(int i = 0; i< 5; i++)
  {
    std::cout<<buildSkewTimes[i]<<" ";
  }
  std::cout<<std::endl;
  std::cout<<"Delete mins ";
  for(int i= 0; i< 5;i++)
  {
    std::cout<<deleteSkewTimes[i]<<" ";
  }
  std::cout<<"\n\n\n";
}
