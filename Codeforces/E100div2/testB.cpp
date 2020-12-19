#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
int a[50+5];
int b[50+5];

void init(){
    for(int i=0;i<55;i++){
        a[i] = 0;
        b[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        init();
        scanf("%d",&n);
        ll sum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(a[0]%2==0){
            b[0] = a[0];
        }else{
            if(a[0]==1) b[0] = 1;
            else b[0] = a[0] - 1;
        }
        for(int i = 1;i<n;i++){
            if(a[i]<=2){
                b[i] = 1;
                continue;
            }
            if(b[i-1]==1){
                b[i] = a[i];
                continue;
            }
            if(a[i]>a[i-1]) b[i] = (a[i]/a[i-1]*b[i-1]);
            else if(a[i]<a[i-1]) b[i] = (b[i-1]/(a[i-1]/a[i]));
            else b[i] = b[i-1];
        }
        cout << b[0];
        for(int i=1;i<n;i++){
            printf(" %d",b[i]);
        }
        cout << endl;
    }

    return 0;
}