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
int n,m,k;
int cost[305][305];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    memset(cost,-1,sizeof(cost));
    cin >> n >> m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    cin >> k;
    int M = INF;
    while(k--){
        set<int> se;
        for(int i=1;i<=n;i++){
            se.insert(i);
        }
        int N;
        cin >> N;
        int Cost = 0;
        int x = 0;
        int y;
        int flag = 0;
        for(int i=0;i<N;i++){
            cin >> y;
            if(se.find(y)==se.end()) flag = 1;
            else{
                se.erase(se.find(y));
            }
            if(cost[x][y]==-1) flag = 1;
            Cost += cost[x][y];
            x = y;
        }
        Cost += cost[y][0];
        if(flag==0){
            if(se.empty()){
                M = min(M,Cost);
            }
        }
    }
    if(M==INF) cout << -1 << endl;
    else cout << M << endl;

    return 0;
}