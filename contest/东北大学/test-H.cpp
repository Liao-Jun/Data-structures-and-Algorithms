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
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
// #define endl '\n'
#define PI acos(-1)
// #define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const ll Mod = 998244353;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
ll n,m;
ll mpow(ll b,ll p,ll k){//a^b
    ll res = 1;
    while(p>0){
        if(p&1) res=res*b%k;
        b = b*b%k;
        p>>=1;
    }
    return res;
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n==1&&m==0) cout << 2 << endl;
        else if(n==0) cout << 1 << endl;
        else if(m==0) cout << (n+2)%Mod << endl;
        else if(m==1) cout << (2*n)%Mod << endl;
        else if(m==2){
            ll sum = mpow(1ll*2,n,Mod);
            cout << sum << endl;
        }
    }

    return 0;
}