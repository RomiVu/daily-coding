#ifndef _BSTREENODE_H
#define _BSTREENODE_H
#include "tree.h"


template <class T>
class BSTree : public Tree
{
public:
	virtual void insert(T &data) { m_insert(this->root, data); }
	virtual TreeNode<T>* search(T &data) {  return m_search(this->root, data); }
	virtual bool remove(T &data);

	virtual TreeNode<T>* minmum(){ return m_minmum(this->root); }
	virtual TreeNode<T>* maxmum(){ return m_maxmum(this->root); }

protected:
	void m_insert(TreeNode<T> *&node, T &value); // insert into a binary search tree

	TreeNode<T>* m_search(TreeNode<T> *node, T &value);  // search the value across the tree.
	TreeNode<T>* m_minmum(TreeNode<T> *node); // find the minmum of tree with the root: node 
	TreeNode<T>* m_maxmum(TreeNode<T> *node); // find the maxmum of tree with the root: node 
	TreeNode<T>* m_remove(TreeNode<T> *&node, TreeNode<T> *target); // remove target node return the removed one

}; // class BSTree



template<class T>
bool BSTree<T>::remove(T &data)
{
	TreeNode<T> *target = m_search(this->root, data);
	if (target) {
		m_remove(this->root, target);
		return true;
	}
	else
		return false;
}

template<class T>
void BSTree<T>::m_insert(TreeNode<T> *&node, T &value) {
	if(node == nullptr) {
		node = new TreeNode<T>(value);
	} else if(value < node->val) {
		m_insert(node->left, value);
	} else
		m_insert(node->right, value);
}


template<class T>
TreeNode<T>* BSTree<T>::m_search(TreeNode<T> *node, T &value) {
	if(node == nullptr) 
		return nullptr;
	else if(value == node->val)
		return node;
	else if(value < node->val)
		return m_search(node->left,value);
	else
		return m_search(node->right,value);
}

template<class T>
TreeNode<T>* BSTree<T>::m_minmum(TreeNode<T> *node)
{
	if (node == nullptr) return nullptr;
	while(node->left){
		node = node->left;
	}
	return node;
}

template<class T>
TreeNode<T>* BSTree<T>::m_maxmum(TreeNode<T> *node)
{
	if (node == nullptr) return nullptr;
	while(node->right){
		node = node->right;
	}
	return node;
}

template<class T>
TreeNode<T>* BSTree<T>::m_remove(TreeNode<T> *&node, TreeNode<T> *target)
{
	if (node == nullptr || target == nullptr ) return nullptr;
	if (target->val < node->val) 
		node->left = m_remove(node->left, target);
	else if (target->val > node->val)
		node->right = m_remove(node->right, target);
	else
	{
		if (node->left != nullptr && node->right != nullptr)
		{
			TreeNode<T> *max = m_maxmum(node->left);
			node->val = max->val;
			node->left = m_remove(node->left, max);
		}
		else
		{
			TreeNode<T> *tmp = node;
			node = (node->left!=nullptr) ? node->left : node->right;
			delete tmp;
		}
	}
	
	return node;
}


#endif
