#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H

#include "bstree.h"

template <class T>
class HuffmanTree : public Tree<T> 
{
public:
	void insert(T &value) {};
	void insert(HuffmanTree<T> &tree) {};
	void insert_left(Tree<T> &tree) {};
	void insert_right(Tree<T> &tree) {};
}; // class HuffmanTree 


#endif