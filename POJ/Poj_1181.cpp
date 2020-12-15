#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

typedef long long ll;

ll q_mul(ll a, ll b, ll mod){//快速积
    a %= mod;
    b %= mod;
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

ll gcd(ll a, ll b){
    if(b==0){
        return a>0?a:-a;
    }
    gcd(b,a%b);
}

ll factor[110];
int cnt;

ll pollard_rho(ll x,ll c){//查找因子
    ll i = 1;
    ll k = 2;
    srand(time(NULL));
    ll x0 = rand()%(x-1)+1;
    ll y = x0;
    while(1){
        i++;
        x0 = (q_mul(x0,x0,x)+c)%x;
        ll d = gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){
            y = x0;
            k += k;
        }
    }
}

void find(ll n, int k){//对n因式分解，因子存在factor中，k一般取107
    if(n==1) return;
    if(Miller_Rabin(n)){
        factor[cnt++] = n;
        return;
    }
    ll p = n;
    int c = k;
    while(p>=n){
        p = pollard_rho(p,c--);
    }
    find(p,k);
    find(n/p,k);
}

int main(){
    int t;
    scanf("%d",&t);
    ll n;
    while(t--){
        scanf("%lld",&n);
        if(Miller_Rabin(n)) printf("Prime\n");
        else{
            cnt = 0;
            find(n,107);
            ll ans = factor[0];
            for(int i=1;i<cnt;i++){
                ans = min(ans,factor[i]);
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1811