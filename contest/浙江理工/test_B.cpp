#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

int gcd(int x){
    for(int i=x/2;i>=1&&i%2!=0;i--){
        if(x%i==0&&i%2==1){
            return i;
        }
    }
    return 1;
}

int main(){
    int t,n;
    scanf("%d",&t);
    ll sum = 0;
    while(t--){
        scanf("%d",&n);
        if(n%2==0){
            printf("clynb\n");
            sum += 1ll*gcd(n);
        }else{
            printf("DD_BONDNB\n");
        }
    }
    printf("%lld\n",sum);
    
    return 0;
}