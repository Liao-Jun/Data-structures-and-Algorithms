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
#include <time.h>
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
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
const int M = 1e6+10;
int n,m;
struct node{
    ll x;
    vector<int> v;
};
node N[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&N[i].x);
    }
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        N[a].v.push_back(b);
        N[b].v.push_back(a);
        if(N[a].x>=N[b].x){
            N[b].x = N[a].x;
            for(auto it:N[b].v){
                N[it].x = N[b].x;
            }
        }else{
            N[a].x = N[b].x;
            for(auto it:N[a].v){
                N[it].x = N[a].x;
            }
        }
    }
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += N[i].x;
    }
    cout << sum << endl;

    return 0;
}