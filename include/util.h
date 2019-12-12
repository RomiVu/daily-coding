#ifndef _UTIL_H
#define _UTIL_H
#include <iostream>
#include <ctime> // for time ()
#include <random> // for mersenne twister
#include <vector>
#include <set>


using namespace std;


void CloseWindow()
{
	cout << "Tap twice 'Enter' to exit the window..." << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
}

namespace MyRandom
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };
}
 
int getRandomNumber(int min, int max){
	uniform_int_distribution<int> die { min, max }; // we can create a distribution in any function that needs it
	return die(MyRandom::mersenne); // and then generate a random number from our global generator
}

double getRandomNumber(double min, double max){
	uniform_real_distribution<double> die {min, max};
	return die(MyRandom::mersenne);
}

int min(int a, int b){
    return (a > b) ? b : a;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int _abs(int a){
	return (a > 0) ? a : -a;
}

// unique random index from [start ,(to) end].
vector<int> randomSample(int start, int end, int k){
	if (end < start) throw 0;

	int n = end - start + 1;
	if (k < 0 || k >n) throw 0;
	vector<int> rslt;
	set<int> choosen;

	int index = getRandomNumber(0.0, 1.0) * n + start;
	while(rslt.size() < k){
		while (choosen.find(index) != choosen.end()) {
			index = getRandomNumber(0.0, 1.0) * n + start;
		}
		rslt.push_back(index);
		choosen.insert(index);
	}

	return rslt;
}


template<typename T>
void printVector(vector<T> &v) {
    for(auto i : v){
        cout << i << ' ';
    }
    cout << endl;
}

#endif
