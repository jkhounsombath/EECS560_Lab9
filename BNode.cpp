#include "BNode.h"

BNode::BNode()
{
	m_entry = 0;
	m_left = nullptr;
	m_right = nullptr;
	m_rank = 0;
}


BNode::BNode(int entry)
{
	m_entry= entry;
	m_left= nullptr;
	m_right= nullptr;
	m_rank = 0;
}

BNode::~BNode()
{

}


int BNode::getEntry() const
{
	return m_entry;
}


BNode* BNode::getLeft() const
{
	return m_left;
}


BNode* BNode::getRight() const
{
	return m_right;
}


void BNode::setEntry(int entry)
{
	m_entry= entry;
}


void BNode::setLeft(BNode* left)
{
	m_left= left;
}


void BNode::setRight(BNode* right)
{
	m_right= right;
}

bool BNode::isLeaf()
{
	return(m_left == nullptr && m_right == nullptr);
}

int BNode::getRank()
{
	return m_rank;
}

void BNode::setRank(int rank)
{
	m_rank = rank;
}
