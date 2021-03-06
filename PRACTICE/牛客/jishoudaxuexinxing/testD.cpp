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
#define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(!y) return x;return gcd(y,y%x);}
inline void debug(){printf("@@\n");}
const int M = 2e6+10;
int a[M];
int n,m;

bool Judge(int x){
    ll t = 0;
    for(int i=0;i<n;i++){
        t += 1ll*(a[i]+x-1)/x;
    }
    return t<=m;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    ll sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int left = 1,right = INF;
    while(right>left){
        int mid = (left+right)>>1;
        if(Judge(mid)) right = mid;
        else left = mid+1;
    }
    printf("%d\n",left);

    return 0;
}