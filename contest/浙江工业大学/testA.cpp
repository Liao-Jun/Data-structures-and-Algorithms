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
struct node{
    ll id,sum,s,p;
};
node N[105];
bool cmp(const node &a, const node &b){
    if(a.sum!=b.sum){
        return a.sum>b.sum;
    }else{
        return a.id<b.id;
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
    ll n,r,l;
    cin >> n >> r >> l;
    for(int i=0;i<n;i++){
        cin >> N[i].id;
    }
    for(int i=0;i<n;i++){
        cin >> N[i].s;
        N[i].sum = N[i].s;
    }
    for(int i=0;i<n;i++){
        cin >> N[i].p;
    }
    while(n>1){
        sort(N,N+n,cmp);
        for(int i=0;i<n;i++){
        }
        n = n-n/2;
        for(int i=0;i<10;i++){
            N[i].sum += r;
        }
        if(n>=6){
            for(int i=0;i<3;i++){
                N[i].sum -= l;
            }
        }
        if(n==1) break;
        for(int i=0;i<n;i++){
            N[i].sum += N[i].p;
        }
    }
    cout << N[0].id << ' ' << N[0].sum << endl;

    return 0;
}