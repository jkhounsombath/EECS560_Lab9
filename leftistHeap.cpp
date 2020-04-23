#include "leftistHeap.h"

leftistHeap::leftistHeap()
{
  m_root = nullptr;
  count = 0;
}

leftistHeap::~leftistHeap()
{
  clear(m_root);
}

void leftistHeap::clear(BNode* curST)
{
  if(curST != nullptr)
  {
    clear(curST->getLeft());
    clear(curST->getRight());
    delete curST;
  }
}


int leftistHeap::rank(BNode* curST)
{
  if(curST == nullptr)
  {
    return -1;
  }
  else
  {
    return std::min(1 + rank(curST->getLeft()), 1 + rank(curST->getRight()));
  }
}


BNode* leftistHeap::merge(BNode* h1, BNode* h2)
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
    h1->setRight(merge(h1->getRight(), h2));
    if(rank(h1->getLeft()) < rank(h1->getRight()))
    {
      BNode* tempNode = h1->getLeft();
      h1->setLeft(h1->getRight());
      h1->setRight(tempNode);
      tempNode = nullptr;
    }
    return h1;
  }
}

void leftistHeap::insert(int entry)
{
  m_root = merge(new BNode(entry), m_root);
  count++;
}

void leftistHeap::print()
{
  for(int i= 0; i < count; i++)
  {
    printHelper(m_root, i);
  }
  std::cout<<std::endl;
}

void leftistHeap::printHelper(BNode* curNode, int level)
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

BNode* leftistHeap::deleteMin()
{
  if(m_root == nullptr)
  {
    std::cout<<"The heap is empty.\n";
    return nullptr;
  }
  else
  {
    m_root = merge(m_root->getLeft(), m_root->getRight());
    count--;
    return m_root;
  }
}
