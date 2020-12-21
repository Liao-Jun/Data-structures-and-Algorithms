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
// #pragma GCC optimize("O3")
// #pragma G++ optimize("O3")
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
const int M = 1e5+10;
int n,m;
vector<int> v[M];
int used[M];

bool dfs(int x){
    queue<int> q;
    q.push(x);
    used[x] = 2;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if(v[s][0]==x) return true;
        if(used[v[s][0]]==1){
            q.push(v[s][0]);
            used[v[s][0]] = 2;
        }
    }
    return false;
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
    int t;
    cin >> t;
    while(t--){
       for(int i=0;i<M;i++){
           v[i].clear();
       }
       memset(used,0,sizeof(used));
       cin >> n >> m;
       int a,b;
       ll sum = 0;
       for(int i=0;i<m;i++){
            cin >> a >> b;
            if(a!=b){
                sum++;
                v[a].push_back(b);
                used[a] = 1;
            }
        }
       for(int i=0;i<n;i++){
           if(used[i]==1&&dfs(i)){
               sum++;
           }
        }
        cout << sum << endl;
    }

    return 0;
}