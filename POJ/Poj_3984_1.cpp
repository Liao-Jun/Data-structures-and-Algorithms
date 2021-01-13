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
int a[5][5];
int used[5][5];
int dic[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
P pre[5][5];
void bfs(){
    queue<P> q;
    q.push(make_pair(0,0));
    used[0][0] = 1;
    while(!q.empty()){
        P N = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = N.first+dic[i][0];
            int y = N.second+dic[i][1];
            if(x>=0&&x<5&&y>=0&&y<5&&a[x][y]!=1&&used[x][y]==0){
                q.push(make_pair(x,y));
                used[x][y] = 1;
                pre[x][y].first = N.first;
                pre[x][y].second = N.second;
                if(x==4&&y==4) return;
            }
        }
    }
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
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> a[i][j];
        }
    }
    memset(used,0,sizeof(used));
    bfs();
    vector<P> v;
    int x = 4,y = 4;
    while(!(x==0&&y==0)){
        v.push_back(make_pair(x,y));
        int x11 = x;
        int y11 = y;
        x = pre[x11][y11].first;
        y = pre[x11][y11].second;
    }
    v.push_back(make_pair(0,0));
    while(v.size()){
        cout << '(' << v.back().first << ", " << v.back().second << ')' << endl;
        v.pop_back();
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3984