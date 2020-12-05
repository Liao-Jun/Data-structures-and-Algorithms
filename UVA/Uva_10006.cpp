#include <iostream>
using namespace std;

typedef long long ll;

bool Isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

ll mpow(ll a,ll n){
    ll res = 1;
    ll mod = n;
    while(n>0){
        if(n&1) res = res*a%mod;
        a = a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    int n;
    while(cin>>n&&n!=0){
        if(Isprime(n)){
            cout << n << " is normal.\n";
        }else{
            int flag = 1;
            for(int i=2;i<n;i++){
                ll x = mpow(i,n);
                if(x%n!=i){
                    flag = -1;
                    break;
                }
            }
            if(flag==-1){
                cout << n << " is normal.\n";
            }else{
                cout << "The number " << n << " is a Carmichael number.\n";
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-10006