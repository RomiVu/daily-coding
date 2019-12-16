#include <vector>
#include <iostream>

using namespace std;


template <class T>
class BinaryHeap
{	
public:
	vector<T> heap;
	bool empty() const { return (heap.size() == 0); }
	T top() const { return heap[0]; }
};


template <class T>
class MinHeap : public BinaryHeap<T>
{
public:
	void pop();
	void push(T &data);
};

template <class T>
class MaxHeap : public BinaryHeap<T>
{
public:
	void pop();
	void push(T &data);
};


template <class T>
void MinHeap<T>::push(T &data){
	this->heap.push_back(data);

	int child = this->heap.size() - 1;
	int parent = (child - 1) / 2;
	while(parent >=0 && this->heap[child] < this->heap[parent]){
		swap(this->heap[child], this->heap[parent]);
		child = parent;
		parent = (parent - 1) / 2;
	}
}

template <class T>
void MinHeap<T>::pop(){
	int n = this->heap.size();
	swap(this->heap[0], this->heap[n-1]);
	this->heap.pop_back();

	if (n < 2) return;

	int parent = 0;
	int child;

	while(true){
		if ((parent*2 + 2) < n-1){
			child = (this->heap[parent*2+1] < this->heap[parent*2+2]) ? parent*2+1 : parent*2+2;
		} else if ((parent*2+1) < n-1){
			child = parent*2 + 1;
			if (this->heap[child] > this->heap[parent]) 
				break; 
		} else
		    break;

		swap(this->heap[parent], this->heap[child]);
		parent = child; 
	}

}


template <class T>
void MaxHeap<T>::push(T &data){
	this->heap.push_back(data);

	int child = this->heap.size() - 1;
	int parent = (child - 1) / 2;
	while(parent >=0 && this->heap[child] > this->heap[parent]){
		swap(this->heap[child], this->heap[parent]);
		child = parent;
		parent = (parent - 1) / 2;
	}
}


template <class T>
void MaxHeap<T>::pop(){
	int n = this->heap.size();
	swap(this->heap[0], this->heap[n-1]);
	this->heap.pop_back();

	n = this->heap.size();
	if (n < 1) return;

	int parent = 0;
	int child;

	while(true){
		if ((parent*2 + 2) < n){
			child = (this->heap[parent*2+1] > this->heap[parent*2+2]) ? parent*2+1 : parent*2+2;
		} else if ((parent*2+1) < n){
			child = parent*2 + 1;
			if (this->heap[child] < this->heap[parent]) 
				break; 
		} else
		    break;

		swap(this->heap[parent], this->heap[child]);
		parent = child; 
	}

}

/*
	MinHeap<int> h1;
	MaxHeap<int> h2;
	std::vector<int> v {1, 7, 5, 4, 6, 8, 3};

	cout << "insering : ";
	for (auto i : v){
		h1.push(i);
		h2.push(i);
		cout << i << ' ';
	}
	cout << '\n';

	cout << "MinHeap : ";
	while(!h1.empty()){
		cout << h1.top() << ' ';
		h1.pop(); 
	}
	cout << '\n';


	cout << "MaxHeap : ";
	while(!h2.empty()){
		cout << h2.top() << ' ';
		h2.pop(); 
	}
  */
