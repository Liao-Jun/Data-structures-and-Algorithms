#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int M = 1e5+10;
int a[M];

int main(){
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x,y;
    while(p--){
        scanf("%d%d",&x,&y);
        int b[M];
        int j = 0;
        for(int i=x-1;i<y;i++){
            b[j++] = a[i];
        }
        sort(b,b+j);
        if(b[j-1]-b[0]<b[0]){
            printf("clynb\n");
        }else{
            printf("clycdd\n");
        }
    }

    return 0;
}