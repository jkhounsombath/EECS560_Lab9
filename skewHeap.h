#ifndef SKEWHEAP_H
#define SKEWHEAP_H

#include <iostream>
#include <string>
#include "BNode.h"

class skewHeap
{
  private:
    BNode* m_root;
    int m_count;
  public:
    skewHeap();
    ~skewHeap();
    void clear(BNode* curST);
    void buildHeap();
    void insert(int entry);
    BNode* merge(BNode* h1, BNode* h2);
    void print();
    void printHelper(BNode* curNode, int level);
    BNode* deleteMin();
};
#endif
