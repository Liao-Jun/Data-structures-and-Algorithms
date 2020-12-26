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
const int M = 2e5+10;
vector<P> v;
int n;

bool cmp(const P &a,const P &b){
    return a.first < b.first;
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
    int n;
    scanf("%d",&n);
    int c;
    int a = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        v.push_back(make_pair(c,0));
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        v[i].second = c;
    }
    sort(v.begin(),v.end(),cmp);
    ll sum = INF;
    int b = 0;
    v.push_back(make_pair(0,0));
    for(int i=n-1;i>=0;i--){
        a = v[i].first;
        b = max(b,v[i+1].second);
        sum = min(sum,(1ll*a)+(1ll*b));
    }
    b = max(b,v[0].second);
    a = 0;
    sum = min(sum,(1ll*a)+(1ll*b));
    cout << sum << endl;

    return 0;
}