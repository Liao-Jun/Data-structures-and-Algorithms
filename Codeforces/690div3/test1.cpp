#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int n;
    int a[300+5];
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        bool left = false;
        bool right = true;
        cout << a[1];
        for(int i=2,j=n;i<=j;){
            if(left&&!right){
                cout << ' ' << a[i];
                i++;
                swap(left,right);
            }else{
                cout << ' ' << a[j];
                j--;
                swap(right,left);
            }
        }
        cout << endl;
    }

    return 0;
}