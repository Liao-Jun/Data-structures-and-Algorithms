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
inline int _max(int a,int b){return a>=b?a:b;}
const int M = 2e5+10;
int a[M];
int n,m,x,y;
char c;
int tree[4*M+10];

void init(int n){
    memset(tree,0,4*n);
}

void build(int node, int l, int r){
    if(l==r){
        tree[node] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    tree[node] = _max(tree[node<<1],tree[node<<1|1]);
}

void update(int node, int l, int r, int x, int y){
    if(l==r){
        tree[node] = y;
        return;
    }
    int mid = (r+l)>>1;
    if(x<=mid) update(node<<1,l,mid,x,y);
    else update(node<<1|1,mid+1,r,x,y);
    tree[node] = _max(tree[node<<1],tree[node<<1|1]);
}

int query(int node, int l, int r, int x, int y){
    if(x<=l&&y>=r) return tree[node];
    int mid = (l+r)>>1;
    int Max = -INF;
    if(x<=mid) Max = _max(Max,query(node<<1,l,mid,x,y));
    if(y>mid) Max = _max(Max,query(node<<1|1,mid+1,r,x,y));
    return Max;
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
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        while(m--){
            scanf(" %c%d%d",&c,&x,&y);
            if(c=='Q'){
                printf("%d\n",query(1,1,n,x,y));
            }else if(c=='U'){
                update(1,1,n,x,y);
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/HDU-1754