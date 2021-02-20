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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int m,n;
    cin >> m >> n;
    map<int,pair<ll,ll>> dic;
    int a;
    string s;
    for(int i=0;i<m;i++){
        cin >> a >> s;
        if(s[0]=='A') dic[a].first++;
        dic[a].second++;
    }
    int flag = 0;
    for(int i=1;i<=n;i++){
        if(dic[i].second==0) continue;
        if(dic[i].first*2>=dic[i].second){
            flag ++;
            if(flag==1) cout << i;
            else cout << ' ' << i;
        }
        if(i==n&&flag>0) cout << endl;
    }
    if(flag==0) cout << -1 << endl;

    return 0;
}