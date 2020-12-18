#include "radixsort.h"
using namespace std;


int getMaxBit(int *arr1, int len){
    int maxBit = 1;
    for(int i = 1; i <= len; i++){
        int tmp = 0, tmp1 = arr1[i];
        if(!tmp1) tmp = 1;
        while(tmp1) {
            tmp++;
            tmp1 /= 10;
        }
        maxBit = max(maxBit, tmp);
    }
    return maxBit;
}

void radixsort(int *arr1, int len){
    vector<int> bucket[15];

    

    int maxBit = getMaxBit(arr1, len);
   // cout<<maxBit<<endl;
    for(int tt = 1; tt <= maxBit; tt++){
        for(int i = 0; i <= 9; i++) bucket[i].clear();
        for(int i = 1; i <= len; i++){
            int tmp = arr1[i];
            for(int j = 1; j <= tt - 1; j++) tmp /= 10;
            tmp %= 10;
            bucket[tmp].push_back(arr1[i]);

        }
        for(int i = 0, j = 0; i <= 9; i++){
            for(auto &x : bucket[i]){
                arr1[++j] = x;
            }
        }
      //  for(int i =1 ; i <= len; i++) cout << arr1[i] << " ";cout<<endl;
    }
    

}
