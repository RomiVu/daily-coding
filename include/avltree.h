#ifndef _AVLTREE_H
#define _AVLTREE_H

#include "bstree.h"
#include <iostream>

using namespace std;

template <class T>
class AVLTree : public Tree<T> 
{
public:
	void insert(T &value) { m_insert(this->root, value); }
	bool remove(T &value);
	int depth(TreeNode<T> *node) { return (node) ? node->depth : 0; }

private:
	TreeNode<T>* m_insert(TreeNode<T>* &tree, T data);
	TreeNode<T>* m_remove(TreeNode<T>* &tree, TreeNode<T> *rm);

	TreeNode<T>* leftLeftRotation(TreeNode<T> *ro);
	TreeNode<T>* rightRightRotation(TreeNode<T> *ro);
	TreeNode<T>* leftRightRotation(TreeNode<T> *ro);
	TreeNode<T>* rightLeftRotation(TreeNode<T> *ro);

}; // class AVLTree

template<class T>
bool AVLTree<T>::remove(T &value) {
		TreeNode<T> *target = this->search(value);
		if (target) {
		    m_remove(this->root, target);
		    return true;
		}
		else
			return false;
}

template<class T>
TreeNode<T>* AVLTree<T>::m_insert(TreeNode<T>* &tree, T data){
    if(tree == nullptr)
    {
        tree = new TreeNode<T> (data);
        if(tree == nullptr)
        {
            cout<<"ERROR: create AVLTree root failed!"<<endl;
            return  nullptr;
        }
    }
    else if(data < tree->val) {
        tree->left = m_insert(tree->left, data);
        if(depth(tree->left) - depth(tree->right) == 2)
        {
            if(data < tree->left->val)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        } 
    }
    else
    {
        tree->right = m_insert(tree->right, data);
        if(depth(tree->right) - depth(tree->left) == 2)
        {
            if(data > tree->right->val)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        } 
    }
    
    tree->depth = max(depth(tree->left), depth(tree->right)) + 1;
    
    return tree;
}

template<class T>
TreeNode<T>* AVLTree<T>::m_remove(TreeNode<T>* &tree, TreeNode<T> *rm){
    if (tree == nullptr || rm == nullptr ) return nullptr;
    if (tree->val > rm->val) 
    {
        tree->left = m_remove(tree->left, rm);
        if(depth(tree->right) - depth(tree->left) == 2)
        {
            if(depth(tree->right->left) < depth(tree->right->right)) 
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }

    }
    else if (tree->val < rm->val)
    {
        tree->right = m_remove(tree->right, rm);
        if(depth(tree->left) - depth(tree->right) == 2)
        {
            if(depth(tree->left->left) < depth(tree->left->right)) 
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        } 
    }
    else
    {
        if (rm->left != nullptr && rm->right != nullptr)
        {
            if(depth(tree->left)>depth(tree->right))
            {
                TreeNode<T> *max = this->m_maxmum(tree->left);
                tree->val = max->val;
                tree->left = m_remove(tree->left, max);
            }
            else
            {
                TreeNode<T> *min = this->m_minmum(tree->right);
                tree->val = min->val;
                tree->right = m_remove(tree->right, min); 
            }
        }
        else
        {
            TreeNode<T> *tmp = tree;
            tree = (tree->left!=nullptr) ? tree->left : tree->right;
            delete tmp;
        }

    }
    
    return tree;
}

template<class T>
TreeNode<T>* AVLTree<T>::leftLeftRotation(TreeNode<T> *ro){
    TreeNode<T>* temp;

    temp = ro->left;
    ro->left = temp->right;
    temp->right = ro;

    ro->depth = max(depth(ro->left), depth(ro->right)) + 1;
    temp->depth = max(ro->depth, depth(temp->left)) + 1;
    return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::rightRightRotation(TreeNode<T> *ro){
    TreeNode<T>* temp;

    temp = ro->right;
    ro->right = temp->left;
    temp->left = ro;

    ro->depth = max(depth(ro->left), depth(ro->right)) + 1;
    temp->depth = max(ro->depth, depth(temp->right)) + 1;
    return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::leftRightRotation(TreeNode<T> *ro){
    ro->left = rightRightRotation(ro->left);
    return leftLeftRotation(ro);
}

template<class T>
TreeNode<T>* AVLTree<T>::rightLeftRotation(TreeNode<T> *ro){
    ro->right = leftLeftRotation(ro->right);
    return rightRightRotation(ro);
}



#endif