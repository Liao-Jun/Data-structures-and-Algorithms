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
const int M = 5e4+10;
int a[M];
int tree[4*M];
void build(int node, int l, int r){
    if(l==r){
        tree[node] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    tree[node] = tree[node<<1]+tree[node<<1|1];
}

void update(int node, int l, int r, int x, int y){
    if(l==r){
        tree[node] += y;
        return;
    }
    int mid = (l+r)/2;
    if(x<=mid) update(node<<1,l,mid,x,y);
    else update(node<<1|1,mid+1,r,x,y);
    tree[node] = tree[node<<1]+tree[node<<1|1];
}

int query(int node, int l, int r, int x, int y){
    if(x<=l&&y>=r){
        return tree[node];
    }
    int mid = (l+r)/2;
    int sum = 0;
    if(x<=mid) sum += query(node<<1,l,mid,x,y);
    if(y>mid) sum += query(node<<1|1,mid+1,r,x,y);
    return sum;
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
    int n;
    int cnt = 0;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        string s;
        int x,y;
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        cnt++;
        cout << "Case " << cnt << ':' << endl;
        while(cin >> s&&s!="End"){
            if(s=="Query"){
                cin >> x >> y;
                cout << query(1,1,n,x,y) << endl;
            }else if(s=="Add"){
                cin >> x >> y;
                update(1,1,n,x,y);
            }else if(s=="Sub"){
                cin >> x >> y;
                update(1,1,n,x,-y);
            }
        }
    }

    return 0;
}