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
inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
const int M = 2e5+10;
int n,m;
ll a[M],b[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    ll x = gcd(abs(a[1]-a[0]),abs(a[2]-a[1]));
    for(int i=3;i<n;i++){
        x = gcd(x,abs(a[i]-a[i-1]));
    }
    if(n==1){
        cout << x+b[0];
        for(int i=1;i<m;i++){
            cout << ' ' << x+b[i];
        }
    }
    else{
        cout << gcd(x,a[0]+b[0]);
        for(int i=1;i<m;i++){
            cout << ' ' << gcd(x,a[0]+b[i]);
        }
    }
    cout << endl;

    return 0;
}