#ifndef _MYSORT_H
#define _MYSORT_H

#include <iostream>
#include <vector>

using namespace std;



template <typename T>
void insertSortDirect(vector<T> &unsorted) 
{
    int n = unsorted.size();
    if (n <= 1) return; // why do the hell sort

    T temp;
    int i, j;
    for (i=1; i<n; i++){
        if (unsorted[i] < unsorted[i-1]){
            temp = unsorted[i];
            for(j=i-1; j >= 0 && unsorted[j] > temp; j--) {
                unsorted[j+1] = unsorted[j];
            }
            unsorted[j+1] = temp;
        }
    }
} // time complexity O(n^2)  STABLE


template <typename T>
void insertSortBinary(vector<T> &unsorted){
    int n = unsorted.size();
    if (n <= 1) return; // why do the hell sort

    int i, j, low, high, mid;
    T temp;
    for (i=1; i<n; ++i){
        temp = unsorted[i];
        if (temp >= unsorted[i-1]) continue;
        high = i - 1;
        low = 0;
        while(low <= high){
            mid = (low + high) / 2;
            if (unsorted[mid] < temp) 
                low = mid+1;
            else
                high = mid-1;
        }

        for(j=i-1; j >= high+1; j--) {
            unsorted[j+1] = unsorted[j];
        }
        unsorted[j+1] = temp;
    }
} // O(n^2), but in common cases faster than above method STABLE

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
    if (low < high){
        int mid = (low + high)/2;
        mergeSort(unsorted, low, mid);
        mergeSort(unsorted, mid+1, high);
        merge(unsorted, low, mid, high);
    }
}

template <typename T>
void merge(vector<T> &unsorted, int low, int mid, int high){
    vector<T> temp;

    for (int i=low; i<=high; i++){
        temp.push_back(unsorted[i]);
    }
    int i, j, k;
    for(i=low, j=mid+1, k=i; i<=mid && j<=high; k++){
        if (temp[i] < temp[j])
            unsorted[k] = temp[i++];
        else
            unsorted[k] = temp[j++];
    }

    while(i <= mid) unsorted[k++] = temp[i++];
    while(j <= high) unsorted[k++] = temp[j++];
}


template <typename T>
void radixSort(vector<T> &unsorted){

}

// to be continued...

template <typename T>
bool isSorted(vector<T> &unsorted){
    int n = unsorted.size();
    for (int i=1; i< n; i++){
        if (unsorted[i-1] > unsorted[i]) return false;
    }
    return true;
}

#endif