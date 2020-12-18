#include "shellsort.h"
using namespace std;

void shellsort(int *arr1, int len){
    //int gap = len;
    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    for(auto &GAP : gaps){
        for(int i = 1; i <= len; i ++){
            for(int j = i; (j >= GAP + 1) && arr1[j] < arr1[j - GAP]; ){
                swap(arr1[j], arr1[j - GAP]);
                j -= GAP;
            }
        }
    }
}