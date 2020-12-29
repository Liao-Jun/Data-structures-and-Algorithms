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
int a[100+5];
int b[100+5];

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
    int n,m;
    while(t--){
        int dp1[100+5];
        int dp2[100+5];
        dp1[0] = 0;
        dp2[0] = 0;
        cin >> n;
        int sum1 = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            dp1[i] = dp1[i-1]+a[i];
            sum1 = max(sum1,dp1[i]);
        }
        cin >> m;
        int sum2 = 0;
        for(int i=1;i<=m;i++){
            cin >> b[i];
            dp2[i] = dp2[i-1]+b[i];
            sum2 = max(sum2,dp2[i]);
        }
        cout << sum1+sum2 << endl;
    }

    return 0;
}