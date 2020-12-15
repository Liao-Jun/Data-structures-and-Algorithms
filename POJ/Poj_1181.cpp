#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll is_prime(ll a){
    for(ll i=2;i*i<=a;i++){
        if(a%i==0){
            return i;
        }
    }
    return a;
}

int main(){
    int t;
    scanf("%d",&t);
    ll a;
    while(t--){
        scanf("%lld",&a);
        ll x = is_prime(a);
        if(x==a){
            printf("Prime\n");
        }else{
            printf("%lld\n",x);
        }
    }

    return 0;
}

//https://vjudge.z180.cn/problem/POJ-1811