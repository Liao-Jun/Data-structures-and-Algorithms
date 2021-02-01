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
const ll Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
ll a,b,m,n;
ll mpow(ll b,ll p,ll k){//b^p
    ll res = 1;
    while(p>0){
        if(p&1) res=res*b%k;
        b = b*b%k;
        p>>=1;
    }
    return res;
}

ll f(ll n){
    if(n==1) return 1ll*1;
    if(n==2) return 1ll*1;
    else return (a*(f(n-1)%Mod)%Mod+b*(f(n-2)%Mod)%Mod)%Mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    cin >> a >> b >> m >> n;
    ll fn = f(n);
    ll s = mpow(m,fn,Mod);
    cout << s%Mod << endl;

    return 0;
}