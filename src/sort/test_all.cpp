#include "mysort.h"
#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

int main ()
{

	vector<int> v;
    for (int i=0;i< 20;i++){
        v.push_back(getRandomNumber(1, 100));
    }
    printVector(v);
    insertSortDirect(v);
    printVector(v);
    cout << "insertSortDirect: " << isSorted(v) << endl;
    v.clear();

    for (int i=0;i< 20;i++){
        v.push_back(getRandomNumber(1, 100));
    }
    printVector(v);
    insertSortBinary(v);
    printVector(v);
    cout << "insertSortBinary: " << isSorted(v) << endl;
    v.clear();


    for (int i=0;i< 20;i++){
        v.push_back(getRandomNumber(1, 100));
    }
    printVector(v);
    insertShellSort(v);
    printVector(v);
    cout << "insertShellSort: " << isSorted(v) << endl;
    v.clear();

}

/* 
template <typename T>
void insertShellSort(vector<T> &unsorted){
    int n = unsorted.size();
    if (n <= 1) return; // why do the hell sort

    int i,j;
    T temp;
    for(int dk=n/2; dk>=1; dk /= 2){
        for(i=dk; i<n; i++){
            if (unsorted[i] < unsorted[i-dk]){
                temp = unsorted[i];
                for(j=i-dk; j>=0&&unsorted[j] > temp; j -= dk){
                    unsorted[j+dk] =unsorted[j];
                }
                unsorted[j+dk] = temp;
            }
        }
    }
} // O(n^1.3) UNSTABLE 

template <typename T>
void swapBubbleSort(vector<T> &unsorted){
    int n = unsorted.size();
    if (n <= 1) return; // why do the hell sort

    bool flag;
    for(int i=0; i<n; i++){
        flag = false;
        for (int j=n-1; j>i; j--){
            if (unsorted[j] < unsorted[j-1])
                swap(unsorted[j], unsorted[j-1]);
                flag = true;
        }
        if (!flag) return;
    }
}

template <typename T>
void swapQuickSort(vector<T> &unsorted, int low, int high){
    if (low == high) return;
    int pivot = Partition(unsorted, low, high);
    swapQuickSort(unsorted, low, pivot-1);
    swapQuickSort(unsorted, pivot+1, high);
}

template <typename T>
int Partition(vector<T> &unsorted, int low, int high){
    T temp = unsorted[low]; //origin low=0; high=unsorted.size()-1

    while(low < high){
        while (low < high && unsorted[high] >= temp) high--;
        unsorted[low] = unsorted[high];
        while (low < high && unsorted[low] <= temp) low++;
        unsorted[high] = unsorted[low];
    }
    unsorted[low] = temp;
    return low;

}


template <typename T>
void selectBasicSort(vector<T> &unsorted){
    int n = unsorted.size();
    if (n <= 1) return; // why do the hell sort

    int min;
    for(int i=0;i<n;i++){
        min = i;
        for (int j=i+1;j<n;j++){
            if (unsorted[j] < unsorted[min]) 
                min = j;
        }
        if (min != i) swap(unsorted[i], unsorted[min]);
    }
}

template <typename T>
void selectHeapSort(vector<T> &unsorted, int n){
    if (n <= 1) return; // n is vector size

    for(int i=(n/2-1); i>=0; i--){
        if(unsorted[2*i+1] > unsorted[i]) 
            swap(unsorted[2*i+1], unsorted[i]);
        if((2*i+2)<n && unsorted[2*i+1] > unsorted[i])
            swap(unsorted[2*i+2], unsorted[i]);
    }
    swap(unsorted[0], unsorted[n-1]);
    selectHeapSort(unsorted, n-1);
}


template <typename T>
void mergeSort(vector<T> &unsorted, int low, int high){
*/