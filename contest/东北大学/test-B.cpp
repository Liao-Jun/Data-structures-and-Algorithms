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
int n,k;
const int M = 1e5+10;
int Hash[M];
ll sum[M];

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
    while(t--){
        memset(Hash,-1,sizeof(Hash));
        memset(sum,0,sizeof(sum));
        Hash[0] = 0;
        cin >> n >> k;
        int Max = 0;
        for(int i=1;i<=n;i++){
            cin >> sum[i];
            sum[i] = (sum[i]+sum[i-1])%k;
            if(Hash[sum[i]]==-1) Hash[sum[i]] = i;
            else Max = max(Max,i-Hash[sum[i]]);
        }
        if(Max) cout << Max << endl;
        else cout << -1 << endl;
    }

    return 0;
}