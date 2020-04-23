#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>

class BNode
{
	public:
		BNode();
		BNode(int entry);
		~BNode();
		int getEntry() const;
		BNode* getLeft() const;
		BNode* getRight() const;
		void setEntry(int entry);
		void setLeft(BNode* left);
		void setRight(BNode* right);
		bool isLeaf();
		void setRank(int rank);
		int getRank();
	private:
		int m_entry;
		BNode* m_left;
		BNode* m_right;
		int m_rank;
};
#endif
