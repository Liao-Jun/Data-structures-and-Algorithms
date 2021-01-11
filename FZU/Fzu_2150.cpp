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
int n,m;
char s[11][11];
int used[11][11];
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    P p;
    int steps;
    node(P _p,int _steps){
        p = _p;
        steps = _steps;
    }
};
int bfs(int a, int b, int c, int d){
    int cnt = 0;
    queue<node> q;
    q.push(node(make_pair(a,b),0));
    q.push(node(make_pair(c,d),0));
    used[a][b] = 1;
    used[c][d] = 1;
    while(!q.empty()){
        node p = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int x = p.p.first+dic[i][0];
            int y = p.p.second+dic[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&used[x][y]==0){
                if(s[x][y]=='.') continue;
                q.push(node(make_pair(x,y),p.steps+1));
                used[x][y] = 1;
                cnt = p.steps+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#'&&used[i][j]==0){
                cnt = -1;
                break;
            }
        }
    }
    return cnt;
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> s[i][j];
            }
        }
        int Max = INF;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='.') continue;
                for(int k=0;k<n;k++){
                    for(int h=0;h<m;h++){
                        memset(used,0,sizeof(used));
                        if(s[k][h]=='#'){
                            int cnt = bfs(i,j,k,h);
                            if(cnt<Max&&cnt!=-1){
                                Max = cnt;
                            }
                        }
                    }
                }
            }
        }
        int res = 1;
        cout << "Case " << res++ << ": "; 
        cout << (Max==INF?-1:Max) << endl;
    }

    return 0;
}

//https://vjudge.net/problem/FZU-2150