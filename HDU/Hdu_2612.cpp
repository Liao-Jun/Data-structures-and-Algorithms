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
char s[205][205];
int used1[205][205];
int used2[205][205];
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    P p;
    int step,flag;
    node(P _p,int _step,int _flag){
        p = _p;
        step = _step;
        flag = _flag;
    }
};
struct Node{
    int cnt1,cnt2;
    int flag1,flag2;
    Node(int _cnt1 = INF,int _cnt2 = INF,int _flag1 = 0,int _flag2 = 0){
        cnt1 = _cnt1;
        cnt2 = _cnt2;
        flag1 = _flag1;
        flag2 = _flag2;
    }
};
int bfs(int a, int b, int c, int d){
    queue<node> q;
    q.push(node(make_pair(a,b),0,1));
    q.push(node(make_pair(c,d),0,2));
    used1[a][b] = 1;
    used2[c][d] = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    Node O[205][205];
    while(!q.empty()){
        node N = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = N.p.first+dic[i][0];
            int y = N.p.second+dic[i][1];
            if(N.flag==1&&x>=0&&x<n&&y>=0&&y<m&&(s[x][y]=='.'||s[x][y]=='@')&&used1[x][y]==0){
                if(s[x][y]=='@'){
                    O[x][y].cnt1 = N.step+1;
                    O[x][y].flag1 = 1;
                }
                q.push(node(make_pair(x,y),N.step+1,1));
                used1[x][y] = 1;
            }else if(N.flag==2&&x>=0&&x<n&&y>=0&&y<m&&(s[x][y]=='.'||s[x][y]=='@')&&used2[x][y]==0){
                if(s[x][y]=='@'){
                    O[x][y].cnt2 = N.step+1;
                    O[x][y].flag2 = 2;
                }
                q.push(node(make_pair(x,y),N.step+1,2));
                used2[x][y] = 1;
            }
        }
    }
    int cnt = INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnt = min(O[i][j].cnt1+O[i][j].cnt2,cnt);
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
    while(cin>>n>>m){
        int a,b,c,d;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> s[i][j];
                if(s[i][j]=='Y'){
                    a = i;
                    b = j;
                }else if(s[i][j]=='M'){
                    c = i;
                    d = j;
                }
            }
        }
        memset(used1,0,sizeof(used1));
        memset(used2,0,sizeof(used2));
        int cnt = bfs(a,b,c,d);
        cout << cnt*11 << endl;
    }

    return 0;
}

//https://vjudge.net/problem/HDU-2612