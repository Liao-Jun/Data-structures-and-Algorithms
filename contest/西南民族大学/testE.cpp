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
const int M = 1e3+5;
int pre[M];

void init(){
    for(int i=0;i<M;i++){
        pre[i] = i;
    }
}

int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
}

void join(int x, int y){
    int rx = find_root(x);
    int ry = find_root(y);
    if(rx!=ry){
        pre[rx] = ry;
    }
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
    int n,d;
    cin >> n >> d;
    P p[M];
    int a,b;
    init();
    for(int i=0;i<n;i++){
        cin >> a >> b;
        p[i].first = a;
        p[i].second = b;
        for(int j=0;j<=i-1;j++){
            if((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second)<=d*d){
                join(i,j);
            }
        }
    }
    set<int> e; 
    for(int i=0;i<n;i++){
        e.insert(find_root(i));
    }
    cout << e.size() << endl;

    return 0;
}