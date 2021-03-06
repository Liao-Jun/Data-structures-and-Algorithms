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
int dic[][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int h,w;
char s[105][105];
int used[105][105];
void dfs(int x, int y,int ch){
    for(int i=0;i<4;i++){
        int nx = x+dic[i][0];
        int ny = y+dic[i][1];
        if(nx>=0&&nx<h&&ny>=0&&ny<w&&used[nx][ny]==0){
            if(s[nx][ny]==ch){
                used[nx][ny] = 1;
                dfs(nx,ny,ch);
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
    while(cin>>h>>w&&!(h==0&&w==0)){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> s[i][j];
            }
        }
        memset(used,0,sizeof(used));
        int cnt = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(used[i][j]==0){
                    dfs(i,j,s[i][j]);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/Aizu-0118