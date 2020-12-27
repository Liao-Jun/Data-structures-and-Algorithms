#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#define endl '\n'
#define PI acos(-1)
// #define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}

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
	srand(0);
	for(int i = 0; i < 4; i++) {//8可为任意数，一般取8~10
		ll a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
			return false;
	}
	return true;
}
const int M = 1e6+10;
int a[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int t;
    int n;
    cin >> t;
    int snt = 0;
    for(int i=2;i<=M;i++){
        if(Miller_Rabin(i)){
            a[snt++] = i;
        }
    }
    while(t--){
        cin >> n;
        int sum1 = 0;
        int sum2 = 0;
        int cnt = 0;
        for(cnt;cnt<snt;cnt++){
            if(a[cnt]>n){
                break;
            }
            cnt++;
        }
        if(cnt%2==1&&cnt/2%2==0){
            cout << "cxy" << endl;
        }else if(cnt%2==1&&cnt/2%2==1){
            cout << -1 << endl;
        }else if(cnt%2==0&&cnt/2%2==1){
            cout << "cxy" << endl;
        }else if(cnt%2==0&&cnt/2%2==0){
            cout << "cxy" << endl;
        }
    }

    return 0;
}