#ifndef _TREENODE_H
#define _TREENODE_H

#include <iostream>
#include <queue>

using namespace std;

template <class T>
struct TreeNode
{
public:
	T val;
	TreeNode *left, *right;
	int depth;
	int children;
	TreeNode() : left(nullptr), right(nullptr) {}
	TreeNode(T &data) : val(data), left(nullptr), right(nullptr) {}
};


template <class T>
class Tree 
{
public:
	Tree() { root = nullptr;}
	Tree(T value) { root = new TreeNode<T>(value);}
	~Tree(){  m_destory(root);}

	virtual void print();
	virtual void print(int direction);
	virtual void insert(T &data) { m_insert(root, data); }
	virtual TreeNode<T>* search(T &data) {  return m_search(root, data); }
	virtual bool remove(T &data);

	virtual TreeNode<T>* minmum(){ return m_minmum(root); }
	virtual TreeNode<T>* maxmum(){ return m_maxmum(root); }
	TreeNode<T>*& getRoot() { return root; }

protected:
	TreeNode<T>* root;

	void preOrderPrint(TreeNode<T> *tree) const;
	void inOrderPrint(TreeNode<T> *tree) const;
	void postOrderPrint(TreeNode<T> *tree) const;
	void levelOrderPrint(TreeNode<T> *tree) const;

	void m_insert(TreeNode<T> *&node, T &value); // insert into a binary search tree
	void m_destory(TreeNode<T>* node); // destroy all children nodes of THIS node, include itself.
	TreeNode<T>* m_search(TreeNode<T> *node, T &value);  // search the value across the tree.
	TreeNode<T>* m_minmum(TreeNode<T> *node); // find the minmum of tree with the root: node 
	TreeNode<T>* m_maxmum(TreeNode<T> *node); // find the maxmum of tree with the root: node 
	TreeNode<T>* m_remove(TreeNode<T> *&node, TreeNode<T> *target); // remove target node return the removed one

}; // class Tree

template<class T>
void Tree<T>::preOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        cout << tree->val << ' ';
        preOrderPrint(tree->left);
        preOrderPrint(tree->right);
    }
}

template<class T>
void Tree<T>::inOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        inOrderPrint(tree->left);
        cout << tree->val << ' ';
        inOrderPrint(tree->right);
    }
}

template<class T>
void Tree<T>::postOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        postOrderPrint(tree->left);
        postOrderPrint(tree->right);
        cout << tree->val << ' ';
    }
}

template<class T>
void Tree<T>::levelOrderPrint(TreeNode<T> *tree) const{
    if (tree == nullptr) return;
    queue<TreeNode<T>*> q;
    TreeNode<T> *temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->val << ' ';
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

template<class T>
void Tree<T>::print(int direction){
    switch(direction){
        case 0:
	    cout << "PreOrder print: ";
            preOrderPrint(root);
            break;
        case 1:
	    cout << "InOrder print: ";
            inOrderPrint(root);
            break;
        case 2:
	    cout << "PostOrder print: ";
            postOrderPrint(root);
            break;
        case 3:
	    cout << "LevelOrder print: ";
            levelOrderPrint(root);
            break;
        default:
	    cout << "InOrder print: ";
            inOrderPrint(root);
    }
    cout << endl;
}

template<class T>
void Tree<T>::print() {
    cout << "inorder print: ";	
    inOrderPrint(root);
    cout << endl;
}

template<class T>
bool Tree<T>::remove(T &data)
{
	TreeNode<T> *target = m_search(root, data);
	if (target) {
		m_remove(root, target);
		return true;
	}
	else
		return false;
}

template<class T>
void Tree<T>::m_insert(TreeNode<T> *&node, T &value) {
	if(node == nullptr) {
		node = new TreeNode<T>(value);
	} else if(value < node->val) {
		m_insert(node->left, value);
	} else
		m_insert(node->right, value);
}

template<class T>
void Tree<T>::m_destory(TreeNode<T>* node) {
	if (node != nullptr){
		m_destory(node->left);
		m_destory(node->right);
		delete node;
	}
}

template<class T>
TreeNode<T>* Tree<T>::m_search(TreeNode<T> *node, T &value) {
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
TreeNode<T>* Tree<T>::m_minmum(TreeNode<T> *node)
{
	if (node == nullptr) return nullptr;
	while(node->left){
		node = node->left;
	}
	return node;
}

template<class T>
TreeNode<T>* Tree<T>::m_maxmum(TreeNode<T> *node)
{
	if (node == nullptr) return nullptr;
	while(node->right){
		node = node->right;
	}
	return node;
}

template<class T>
TreeNode<T>* Tree<T>::m_remove(TreeNode<T> *&node, TreeNode<T> *target)
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
