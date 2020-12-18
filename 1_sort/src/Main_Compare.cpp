#include "../mylib/InsertSort/insertsort.h"
#include "../mylib/MergeSort/mergesort.h"
#include "../mylib/QuickSort/quicksort.h"
#include "../mylib/RadixSort/radixsort.h"
#include "../mylib/ShellSort/shellsort.h"
using namespace std;
int a[100005], b[100005];
int an;
bool showResult;


int main(int argc,char *argv[]){
     freopen(argv[1], "r", stdin);
    if(argc >= 3){
        if(strcmp(argv[2], "true") == 0) showResult = true;
        else if(strcmp(argv[2], "false") == 0) showResult = false;
    }
    else showResult = false;

    cin >> an;
    for(int i = 1; i <= an; i++) cin >> b[i];
    memcpy(a, b, sizeof(b));
    long long timeNow = clock();
    shellsort(a, an);
    cout<<"time consumption of shellsort:" << clock() - timeNow << endl;
    if(showResult){
        cout<<"results of shellsort:" << endl;
        for(int i = 1; i <= an; i++) cout << a[i] << " ";
    }
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
    memcpy(a, b, sizeof(b));
    timeNow = clock();
    quicksort(a, 1, an);
   cout<<"time consumption of quicksort:" << clock() - timeNow << endl;
   if(showResult){
        cout<<"results of quicksort:" << endl;
        for(int i = 1; i <= an; i++) cout << a[i] << " ";
   }
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
    
    memcpy(a, b, sizeof(b));
    timeNow = clock();
    insertsort(a, an);
    cout<<"time consumption of insertsort:" << clock() - timeNow << endl;
    if(showResult){
        cout<<"results of insertsort:" << endl;
        for(int i = 1; i <= an; i++) cout << a[i] << " ";
    }
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
    
    bool neg = false;
    int tmp = 0x3f3f3f3f;
    memcpy(a, b, sizeof(b));
    for(int i = 1; i <= an; i++) {
        if(a[i] < 0){
            neg = true;
            tmp = min(tmp, a[i]);
        }
    }
    if(neg)
        for(int i = 1; i <= an; i++) a[i] -= tmp;

    timeNow = clock();
    radixsort(a, an);
    cout<<"time consumption of radixsort:" << clock() - timeNow << endl;
    if(showResult){
        cout<<"results of radixsort:" << endl;
        
        for(int i = 1; i <= an; i++){
            if(neg)
                cout << a[i] + tmp << " ";
            else cout << a[i] << " ";
        }
    }
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
    
    memcpy(a, b, sizeof(b));
    timeNow = clock();
    int c[100005];
    mergesort(a, 1, an, c);
    cout<<"time consumption of mergesort:" << clock() - timeNow << endl;
    if(showResult){
        cout<<"results of mergesort:" << endl;
        for(int i = 1; i <= an; i++) cout << a[i] << " ";
    }
    cout << endl << "----------------------------------------------------------------------------------------------" << endl;
    return 0;
}