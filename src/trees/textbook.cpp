#include "tree.h"
#include "util.h"
#include <iostream>


using namespace std;



int main(){
	int temp;
	temp = getRandomNumber(1, 100);
	Tree<int> t(temp);
	TreeNode<int>* ptr;

	ptr = t.getRoot();
	
	temp = getRandomNumber(1, 100);
	ptr->left = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->right = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->left->right = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->left->left = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->left->left->right = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->right->left = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->left->right->left = new TreeNode<int>(temp);
	
	temp = getRandomNumber(1, 100);
	ptr->right->left->right = new TreeNode<int>(temp);
	
	t.print(0);
	t.print(1);
	t.print(2);
	t.print(3);

	cout << t.countLeafNodes() << " leaves :  double: " << t.countNodesofDoubleChild() << endl;

}

