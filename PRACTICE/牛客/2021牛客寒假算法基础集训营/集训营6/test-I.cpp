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
int n,m;
int x11,y11,x22,y22;
char a[105][105];
int dic[][2] = {{1,0},{0,-1},{0,1},{-1,0}};
int used[105][105];
struct node{
    int x,y,step;
    node(int _x=0, int _y=0, int _step=0){
        x = _x;
        y = _y;
        step = _step;
    }
};
int bfs(){
    memset(used,0,sizeof(used));
    queue<node> q;
    q.push(node(x11,y11,0));
    used[x11][y11] = 1;
    while(!q.empty()){
        node N;
        N = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = N.x+dic[i][0];
            int y = N.y+dic[i][1];
            if(x==x22&&y==y22) return N.step+1;
            if(x>0&&x<=n&&y>=0&&y<=m&&used[x][y]==0&&a[x][y]=='.'){
                used[x][y] = 1;
                q.push(node(x,y,N.step+1));
            }
        }
    }
    return -1;
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
    cin >> n >> m;
    cin >> x11 >> y11 >> x22 >> y22;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int cnt = bfs();
    if(cnt==-1) cout << cnt << endl;
    else cout << cnt << "00" << endl;

    return 0;
}