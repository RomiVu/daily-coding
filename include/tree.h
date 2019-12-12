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

	void print();
	void print(int direction);

    	int countNodesofDoubleChild() {  return m_countDouble(root); }
        int countLeafNodes() { return m_countLeafNodes(root); }

	TreeNode<T>*& getRoot() { return root; }
	bool isCompleteTree() { return m_isComplete(root); }
	bool isBSTree() { return m_isBSTree(root); }
	bool isAVLTree() { return m_isAVLTree(root); }

protected:
	TreeNode<T>* root;

	void preOrderPrint(TreeNode<T> *tree) const;
	void inOrderPrint(TreeNode<T> *tree) const;
	void postOrderPrint(TreeNode<T> *tree) const;
	void levelOrderPrint(TreeNode<T> *tree) const;

	void m_destory(TreeNode<T>* node); // destroy all children nodes of THIS node, include itself.
	int m_countLeafNodes(TreeNode<T>* node) const;
	bool isCompleteTree(TreeNode<T>* node) const;
	int m_countDouble(TreeNode<T>* node) const;
	bool m_isBSTree(TreeNode<T>* node) const;
	bool m_isAVLTree(TreeNode<T>* node) const;

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
void Tree<T>::m_destory(TreeNode<T>* node) {
    if (node != nullptr){
        m_destory(node->left);
        m_destory(node->right);
        delete node;
    }
}

template<class T>
int Tree<T>::m_countDouble(TreeNode<T>* root) const {
    static int count = 0;
    if (root != nullptr){
    	m_countDouble(root->left);
    	m_countDouble(root->right);
	if (root->left && root->right) count++;
    }
    return count;
}


template<class T>
int Tree<T>::m_countLeafNodes(TreeNode<T>* node) const {
    static int count = 0;
    if (node){
	   m_countLeafNodes(node->left);
	   m_countLeafNodes(node->right);
	   if (!node->left && !node->right) count++; 
    }
    return count;
}

template<class T>
bool Tree<T>::m_isCompleteTree(TreeNode<T>* node) const {
    static int count = 0;
    if (node){
	   m_countLeafNodes(node->left);
	   m_countLeafNodes(node->right);
	   if (!node->left && !node->right) count++; 
    }
    return count;
}

template<class T>
int Tree<T>::m_isBSTree(TreeNode<T>* node) const {
    static int count = 0;
    if (node){
	   m_countLeafNodes(node->left);
	   m_countLeafNodes(node->right);
	   if (!node->left && !node->right) count++; 
    }
    return count;
}

template<class T>
int Tree<T>::m_countLeafNodes(TreeNode<T>* node) const {
    static int count = 0;
    if (node){
	   m_countLeafNodes(node->left);
	   m_countLeafNodes(node->right);
	   if (!node->left && !node->right) count++; 
    }
    return count;
}


#endif
