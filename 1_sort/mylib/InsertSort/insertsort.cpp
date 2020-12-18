#include "insertsort.h"
using namespace std;

void insertsort(int *arr1, int len){
    for(int i = 1; i <= len; i++){
        int j = upper_bound(arr1 + 1, arr1 + i, arr1[i]) - arr1;
        // for(int l = 1; l <= i - 1; l++) cout << arr1[l] <<" ";
        // cout << endl<< arr1[i] <<" "<<j<<endl;
        int tmp = arr1[i];
        for(int k = i; k > j; k--) arr1[k] = arr1[k - 1];
        arr1[j] = tmp;
    }
}