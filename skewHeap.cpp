#include "skewHeap.h"

skewHeap::skewHeap()
{
  m_root = nullptr;
  m_count = 0;
}

skewHeap::~skewHeap()
{
  clear(m_root);
}

void skewHeap::clear(BNode* curST)
{
  if(curST != nullptr)
  {
    clear(curST->getLeft());
    clear(curST->getRight());
    delete curST;
  }
}

void skewHeap::buildHeap()
{

}

BNode* skewHeap::merge(BNode* h1, BNode* h2)
{
  if(h1 == nullptr)
  {
    return h2;
  }
  else if(h2 == nullptr)
  {
    return h1;
  }
  else
  {
    if(h1->getEntry() > h2->getEntry())
    {
      BNode* tempNode = h1;
      h1 = h2;
      h2 = tempNode;
      tempNode = nullptr;
    }
    BNode* tempNode = h1->getLeft();
    h1->setLeft(h1->getRight());
    h1->setRight(tempNode);
    h1->setLeft(merge(h2, h1->getLeft()));
    return h1;
  }
}

void skewHeap::insert(int entry)
{
  m_root = merge(new BNode(entry), m_root);
  m_count++;
}

void skewHeap::print()
{
  for(int i= 0; i < m_count; i++)
  {
    printHelper(m_root, i);
  }
  std::cout<<std::endl;
}

void skewHeap::printHelper(BNode* curNode, int level)
{
  if(curNode == nullptr)
  {
    return;
  }
  else if(level == 1)
  {
    std::cout<< curNode->getEntry() << " ";
  }
  else if(level > 1)
  {
    printHelper(curNode->getLeft(), level - 1);
    printHelper(curNode->getRight(), level - 1);
  }
}

BNode* skewHeap::deleteMin()
{
  if(m_root == nullptr)
  {
    std::cout<<"The heap is empty.\n";
    return nullptr;
  }
  else
  {
    m_root = merge(m_root->getLeft(), m_root->getRight());
    m_count--;
    return m_root;
  }
}
