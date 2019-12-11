#include "tree.h"
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	AVLTree<int> t;
	vector<int> values {1,2,3,4,5,6,7,8,9,10};
	
	for (auto i : values){
	    t.insert(i);
	}
	
	t.print(3);
	t.print(2);
	t.print(1);
	t.print(0);
}
