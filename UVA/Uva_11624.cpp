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
char s[1005][1005];
int n,m;
int used[1005][1005];
int dic[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
struct node{
    P p;
    int step,flag;
    node(P _p, int _step, int _flag = 1){
        p = _p;
        step = _step;
        flag = _flag;
    }
};
vector<P> v;
int bfs(int a, int b){
    queue<node> q;
    q.push(node(make_pair(a,b),0,1));
    for(auto it:v){
        q.push(node(make_pair(it.first,it.second),0,2));
        used[it.first][it.second] = 2;
    }
    used[a][b] = 1;
    while(!q.empty()){
        node N = q.front();
        q.pop();
        if(N.flag==1&&used[N.p.first][N.p.second]==2){
            continue;
        }
        for(int i=0;i<4;i++){
            if(N.flag==1&&(N.p.first==n-1||N.p.second==m-1||N.p.first==0||N.p.second==0)) return N.step+1;
            int x = N.p.first+dic[i][0];
            int y = N.p.second+dic[i][1];
            if(N.flag==1&&x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.'&&used[x][y]==0){
                q.push(node(make_pair(x,y),N.step+1,1));
                used[x][y] = 1;
            }else if(N.flag==2&&x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='.'&&used[x][y]!=2){
                q.push(node(make_pair(x,y),N.step+1,2));
                used[x][y] = 2;
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
        cin >> n >> m;
        int a,b;
        v.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> s[i][j];
                if(s[i][j]=='J'){
                    a = i;
                    b = j;
                }else if(s[i][j]=='F'){
                    v.push_back(make_pair(i,j));
                }
            }
        }
        memset(used,0,sizeof(used));
        int cnt = bfs(a,b);
        if(cnt==-1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << cnt << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-11624