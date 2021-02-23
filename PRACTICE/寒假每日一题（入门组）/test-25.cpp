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
int r,c;
int x11,y11,x22,y22;
char a[205][205];
int used[205][205];
int dic[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct node{
    int x,y,step;
    node(int _x = 0,int _y = 0, int _step = 0){
        x = _x;
        y = _y;
        step = _step;
    }
};
int bfs(){
    memset(used,0,sizeof(used));
    queue<node> q;
    q.push(node(x11,y11,0));
    while(!q.empty()){
        node N;
        N = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = N.x+dic[i][0];
            int y = N.y+dic[i][1];
            if(x>=0&&x<r&&y>=0&&y<c&&a[x][y]=='E') return N.step+1;
            if(x>=0&&x<r&&y>=0&&y<c&&a[x][y]=='.'&&used[x][y]==0){
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
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> a[i][j];
                if(a[i][j]=='S') x11 = i, y11 = j;
                if(a[i][j]=='E') x22 = i, y22 = j;
            }
        }
        int cnt = bfs();
        if(cnt==-1) cout << "oop!" << endl;
        else cout << cnt << endl;
    }

    return 0;
}