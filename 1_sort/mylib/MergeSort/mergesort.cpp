#include "mergesort.h"
using namespace std;


void mergesort(int *arr1, int from, int end, int *arr2){
    if(end <= from) return;
    int mid = from + end >> 1;
    mergesort(arr1, from, mid, arr2);
    mergesort(arr1, mid + 1, end, arr2);

    int ind = from, i, j;
    for(i = from, j = mid + 1; (i <= mid)&&(j <= end); ){
        if(arr1[i] < arr1[j]) arr2[ind++] = arr1[i++];
        else arr2[ind++] = arr1[j++];
    }
    while(i <= mid) arr2[ind++] = arr1[i++];
    while(j <= end) arr2[ind++] = arr1[j++];
    for(int k = from; k <= end; k++) arr1[k] = arr2[k];
}