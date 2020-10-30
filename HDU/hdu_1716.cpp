#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[4];
    int n = 0;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]&&!(a[0]==0&&a[2]==0&&a[1]==0&&a[3]==0)){
        if(n){
            cout << endl;
        }
        n++;
        int sum = 0;
        int t;
        int i=0;
        t=a[0];
        int m = 0;
        do{
            if(a[0]==0){
                if(t==0){
                    int j = 1;
                    for(j;j<4;j++){
                        if(t==0)t=a[j];
                    }
                }
                continue;
            }
            if(m){
                if(t==a[0]){
                    cout << ' ';
                }else{
                cout << endl;
                    t=a[0];
                } 
            }
            m++;
            for(int i=0;i<4;i++){
                cout << a[i];
            }
        }while(next_permutation(a,a+4));
        cout << endl;
    }

    return 0;
}