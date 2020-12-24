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
// #define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(!y) return x;return gcd(y,y%x);}
inline void debug(){printf("@@\n");}
const int M = 1e5+10;
ll a[M];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    ll sum = 0;
    ll S = 0;
    int b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&b);
            sum += (1ll*b);
            a[j] += (1ll*b);
        }
        S = max(S,sum);
        sum = 0;
    }
    sort(a,a+m);
    S = max(S,a[m-1]);
    printf("%lld\n",S);

    return 0;
}