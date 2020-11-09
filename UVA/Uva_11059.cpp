#include <iostream>
using namespace std;

int main(){
    int n;
    int sum = 1;
    while(scanf("%d",&n)==1){
        int a[20];
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        long long re=0, p=1;
        for(int i=0;i<n;i++){
            p=1;
            for(int j=i;j<n;j++){
                p *= (long long)a[j];
                if(re<=p){
                    re = p;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",sum++,re);
    }

    return 0;
}

//https://vjudge.net/problem/UVA-11059