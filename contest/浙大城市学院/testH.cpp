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
int n,m;
const int M = 1e5+10;
int a[M];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        ll sum = 0;
        int akmax;
        int lingmax;
        int lingmin = 0;
        int akmin;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum += (1ll*a[i]);
        }
        if(sum<=m){
            lingmin = m-sum;
        }
        sort(a,a+n);
        akmax = a[0];
        lingmax = m - a[n-1];
        int s = a[0];
        for(int i=1;i<n;i++){
            s += a[i];
            if(s>m){
                s -= m;
                akmin = s;
            }else{
                akmin = 0;
                break;
            }
        }
        printf("%d %d\n%d %d\n",akmin,akmax,lingmin,lingmax);
    }

    return 0;
}