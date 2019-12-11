#ifndef _TREENODE_H
#define _TREENODE_H
#include <iostream>
#include <stack>
#include <queue>
#include <set>


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
	Tree() 
	{
	    root = nullptr;
	}

	Tree(T value) 
	{
	    root = new TreeNode<T>(value);
	}

	~Tree()
	{
	    m_destory(root);
	}

	virtual void print();

	virtual void print(int direction);

	virtual void insert(T &data)
	{
	    m_insert(root, data);
	}
	
	virtual TreeNode<T>* search(T &data)
	{
	    return m_search(root, data);
	}

	virtual bool remove(T &data)
	{
		TreeNode<T> *target = m_search(root, data);
		if (target) {
		    m_remove(root, target);
		    return true;
		}
		else
		    return false;
	}

	virtual TreeNode<T>* minmum()
	{
	    return m_minmum(root);
	}

	virtual TreeNode<T>* maxmum()
	{
	    return m_maxmum(root);
	}

	TreeNode<T>*& getRoot()
	{
	    return root;
	}

protected:
	TreeNode<T>* root;

	void preOrderPrint(TreeNode<T> *tree) const;
	void inOrderPrint(TreeNode<T> *tree) const;
	void postOrderPrint(TreeNode<T> *tree) const;
	void levelOrderPrint(TreeNode<T> *tree) const;

	void m_insert(TreeNode<T> *&node, T &value) {
		if(node == nullptr) {
		    node = new TreeNode<T>(value);
		} else if(value < node->val) {
			m_insert(node->left, value);
		} else
			m_insert(node->right, value);
	}

	void m_destory(TreeNode<T>* node) {
		if (node != nullptr){
			m_destory(node->left);
			m_destory(node->right);
			delete node;
		}
	}

	TreeNode<T>* m_search(TreeNode<T> *node, T &value) {
		if(node == nullptr) 
			return nullptr;
		else if(value == node->val)
			return node;
		else if(value < node->val)
			return m_search(node->left,value);
		else
			return m_search(node->right,value);
	}

	TreeNode<T>* m_minmum(TreeNode<T> *node)
	{
		if (node == nullptr) return nullptr;
		while(node->left){
			node = node->left;
		}
		return node;
	}

	TreeNode<T>* m_maxmum(TreeNode<T> *node)
	{
		if (node == nullptr) return nullptr;
		while(node->right){
			node = node->right;
		}
		return node;
	}

	TreeNode<T>* m_remove(TreeNode<T> *&node, TreeNode<T> *target)
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



template <class T>
class HuffmanTree : public Tree<T> 
{
public:
	void insert(T &value) {};
	void insert(HuffmanTree<T> &tree) {};
	void insert_left(Tree<T> &tree) {};
	void insert_right(Tree<T> &tree) {};
}; // class HuffmanTree 



template <class T>
class AVLTree : public Tree<T> 
{
public:
	void insert(T &value) 
	{ 
		m_insert(this->root, value); 
	}

	bool remove(T &value) 
	{
		TreeNode<T> *target = this->search(value);
		if (target) {
		    m_remove(this->root, target);
		    return true;
		}
		else
			return false;
	}

	int depth(TreeNode<T> *node) {
		return (node) ? node->depth : 0;
	}


private:
	TreeNode<T>* m_insert(TreeNode<T>* &tree, T data);
	TreeNode<T>* m_remove(TreeNode<T>* &tree, TreeNode<T> *rm);

	TreeNode<T>* leftLeftRotation(TreeNode<T> *ro);
	TreeNode<T>* rightRightRotation(TreeNode<T> *ro);
	TreeNode<T>* leftRightRotation(TreeNode<T> *ro);
	TreeNode<T>* rightLeftRotation(TreeNode<T> *ro);

}; // class AVLTree

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
