#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 2e5+10;
typedef long long ll;
ll a[M],b[M];

ll gcd(ll a, ll b){
    if(b==0) return a;
    gcd(b,a%b);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&b[i]);
    }
    ll temp = a[0];
    sort(a,a+n);
    for(int i=1;i<n-1;i++){
        temp = gcd(temp,a[i]);
    }
    ll c;
    for(int i=0;i<m;i++){
        c = gcd(temp+b[i],a[n-1]+b[i]);
        printf("%lld\n",c);
    }

    return 0;
}