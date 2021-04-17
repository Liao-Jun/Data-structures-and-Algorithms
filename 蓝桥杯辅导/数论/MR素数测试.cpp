#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef ll ll;

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
        if(b&1) res = q_mul(res,a,mod);
        a = q_mul(a,a,mod);
        b >>= 1;
    }
    return res%mod;
}

bool check(ll a,ll n,ll x,ll t) {//检测
	ll ret = q_pow(a,x,n);
	ll last = ret;
	for(int i = 1; i <= t; i++) {
		ret = q_mul(ret,ret,n);
		if(ret == 1 && last != 1 && last != n-1)return true;//合数
		last = ret;
	}
	if(ret != 1)return true;
	else return false;
}

bool Miller_Rabin(ll n) {//米勒罗宾素数检测
	if( n < 2)return false;
	if( n == 2)return true;
	if( (n&1) == 0)return false;//偶数
	ll x = n - 1;
	ll t = 0;
	while( (x&1)==0 ) {
		x >>= 1;
		t++;
	}
	srand(time(NULL));
	for(int i = 0; i < 8; i++) {//8可为任意数，一般取8~10
		ll a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
			return false;
	}
	return true;
}

int main(){
    for(ll i=1;i<100;i++){
        if(Miller_Rabin(i)) cout << i << endl;
    }

    return 0;
}