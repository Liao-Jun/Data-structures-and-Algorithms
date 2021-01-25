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
// #define endl '\n'
#define PI acos(-1)
#define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
int w,h;
int s[21][21];
int x11,y11,x22,y22;
int dic[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int change[21][21];
struct node{
    int x,y;
    int dir,step;
    node(int _x, int _y, int _dir, int _step){
        x = _x;
        y = _y;
        dir = _dir;
        step = _step;
    }
};
int bfs(){
    memset(change,0,sizeof(change));
    queue<node> q;
    q.push(node(x11,y11,-1,0));
    while(!q.empty()){
        node N = q.front();
        q.pop();
        if(N.x==x22&&N.y==y22) return N.step;
        if(N.dir==-1){
            for(int i=0;i<4;i++){
                int x = N.x+dic[i][0];
                int y = N.y+dic[i][1];
                if(x>=0&&x<h&&y>=0&&y<w&&(s[x][y]==0||s[x][y]==2||s[x][y]==3||(s[x][y]==1&&change[x][y]==1))){
                    q.push(node(x,y,i,N.step+1));
                }
            }
        }else{
            int x = N.x+dic[N.dir][0];
            int y = N.y+dic[N.dir][1];
            if(x>=0&&x<h&&y>=0&&y<w){
                if(s[x][y]==0||(s[x][y]==1&&change[x][y]==1)){
                    q.push(node(x,y,N.dir,N.step));
                }else if(s[x][y]==1){
                    change[x][y] = 1;
                    q.push(node(N.x,N.y,-1,N.step));
                }else if(s[x][y]==3){
                    q.push(node(x,y,N.dir,N.step));
                }
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
    while(cin>>w>>h&&!(w==0&&h==0)){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> s[i][j];
                if(s[i][j]==2){
                    x11 = i;
                    y11 = j;
                }
                if(s[i][j]==3){
                    x22 = i;
                    y22 = j;
                }
            }
        }
        int cnt = bfs();
        if(cnt>10) cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3009