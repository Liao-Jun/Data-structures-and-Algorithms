#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <time.h>
using namespace std;

typedef long long ll;
const ll Mod = 1e9+7;
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
	for(int i = 0; i < 10; i++) {//8可为任意数，一般取8~10
		ll a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
			return false;
	}
	return true;
}

ll gcd(ll a, ll b){//辗转相除法
    if(b==0){
        return a>0?a:-a;
    }
    return gcd(b,a%b);
}

ll factor[110];//结果无序
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
    ll n;
    scanf("%lld",&n);
    ll sum = 0;
    for(ll j=2;j<=n;j++){
        if(Miller_Rabin(j)){
            sum += j;
            sum %= Mod;
        }else{
            cnt = 0;
            find(j,107);
            sort(factor,factor+cnt);
            ll ans = factor[0];
            for(int i=1;i<cnt;i++){
                ll t = 10;
                ll y = factor[i];
                while(y>10){
                    y/=10;
                    t*=10;
                }
                ans = ans*t+factor[i];
                ans %= Mod;
            }
            sum += ans;
            sum %= Mod;
        }
    }
    cout << sum%Mod << endl;

    return 0;
}