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
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int M =1e6+10;
struct node{
    string s,m,x,h;
    int s1;
};
node a[M];
bool cmp(const node &a, const node &b){
    if(a.s1==b.s1){
        return a.s.compare(b.s);
    }else{
        return a.s1<b.s1;
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
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].s >> a[i].m >> a[i].x >> a[i].h;
        a[i].s1 = a[i].s.length();
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout << a[i].s << ' ' << a[i].m << ' ' << a[i].x << ' ' << a[i].h << endl;
    }

    return 0;
}