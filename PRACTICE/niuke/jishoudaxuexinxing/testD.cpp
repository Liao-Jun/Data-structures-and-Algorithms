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
const int M = 2e6+10;
int a[M];
int n,m;

bool Judge(int x){
    int t = 0;
    for(int i=0;i<n;i++){
        t += ceil(a[i]/x);
    }
    if(t<=m) return true;
    else return false;
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
    int left = 0,right = INF;
    int Min = INF;
    while(right-left>1){
        int mid = (left+right)/2;
        if(Judge(mid)) right = mid-1;
        else left = mid+1;
        Min = min(Min,mid);
    }
    printf("%d\n",Min);

    return 0;
}