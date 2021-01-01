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
    int a,b,c;
};
node x[100+5];
bool cmp(const node &a, const node &b){
    return a.b<b.b;
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
    int n,r;
    int sum = 0;
    cin >> n >> r;
    for(int i=0;i<n;i++){
        cin >> x[i].a >> x[i].b >> x[i].c;
        x[i].c -= x[i].a;
        sum += x[i].a;
    }
    sort(x,x+n,cmp);
    int cnt = 0;
    int res = 0;
    int re = r-sum;
    while(re>0){
        if(re<x[cnt].c){
            res += (re)*x[cnt].b;
            re = 0;
        }else{
            res += (x[cnt].c)*x[cnt].b;
            re -= x[cnt].c;
            cnt++;
        }
    }
    cout << res << endl;

    return 0;
}