#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    gcd(b,a%b);
}

int main(){
    ll a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        ll x = gcd(a,b);
        printf("%lld %lld\n",x,a*b/x);
    }

    return 0;
}

//https://vjudge.z180.cn/problem/Aizu-0005