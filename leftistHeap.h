#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include <iostream>
#include <string>
#include "BNode.h"

class leftistHeap
{
  private:
    BNode* m_root;
    int count;
  public:
    leftistHeap();
    ~leftistHeap();
    void clear(BNode* curST);
    int rank(BNode* curST);
    BNode* merge(BNode* h1, BNode* h2);
    void insert(int entry);
    void print();
    void printHelper(BNode* curNode, int level);
    BNode* deleteMin();
};
#endif
