#include "quicksort.h"
#include <iostream>
using namespace std;


//常数极大无比
int partition(int *arr1, int from, int end){
    //int now = arr1[end]; //choose the right most one;

    // int now = arr1[from + end >> 1]; 
    // swap(arr1[from + end >> 1], arr1[end]);

    // int now = arr1[from];
    // swap(arr1[from], arr1[end]);
    //cout << from << " " << end << endl;
    int randIndex = rand() % (end - from + 1) + from;
    int now = arr1[randIndex];
    swap(arr1[end], arr1[randIndex]);

    int largerStartPos = from;
    for(int i = from; i <= end - 1; i++){
        if(arr1[i] < now) {
            swap(arr1[largerStartPos], arr1[i]);
            largerStartPos++;
        }
    }
    swap(arr1[end], arr1[largerStartPos]);
    //cout << from << " " << end << " " << now << " " << largerStartPos << endl;
    return largerStartPos;
}


//Hoare-Partition
int partition2(int *arr1, int from, int end){
   int randIndex = rand() % (end - from + 1) + from;
    int x = arr1[randIndex];
    swap(arr1[from], arr1[randIndex]);

    int i = from - 1;
    int j = end + 1;
    while(true){
        do{
            j--;
        } while(arr1[j] > x);
        do{
            i++;
        }while(arr1[i] < x);
        if(i < j) swap(arr1[i], arr1[j]);
        else return j;
    }
}

 void quicksort(int *arr1, int from, int end){
    if(end <= from) return;
    int partitionPos = partition2(arr1, from, end);
    quicksort(arr1, from, partitionPos );
    quicksort(arr1, partitionPos + 1, end);

}