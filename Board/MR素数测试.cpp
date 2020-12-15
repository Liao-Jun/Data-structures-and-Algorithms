#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll q_mul(ll a, ll b, ll mod){//快速积
    ll res = 0;
    while(b>0){
        if(b&1) res = (res+a)%mod;
        a = (a<<1)%mod;
        b >>= 1;
    }
    return res%mod;
}

ll q_pow(ll a, ll b, ll mod){//快速幂
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

bool Miller_Rabin(ll n){
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    int t = 2, r = 0;
    int m = n-1;
    while(m%2==0){
        r++;
        m >>= 1;
    }
    srand(100);
    while(t--){
        ll a = rand()%(n-1)+1;
        ll x = q_pow(a,m,n);
        ll tmp = 0;
        for(int i=1;i<r;i++){
            tmp = q_mul(x,x,n);
            if(tmp==1&&x!=1&&x!=n-1) return false;
            x = tmp;
        }
        if(tmp!=1) return false;
    }
    return true;
}

int main(){
    for(ll i=1;i<100;i++){
        if(Miller_Rabin(i)) cout << i << endl;
    }


    return 0;
}