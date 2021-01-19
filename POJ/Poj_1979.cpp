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
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int w,h,a,b;
char s[22][22];
int cnt = 0;
void bfs(){
    queue<P> q;
    q.push(make_pair(a,b));
    cnt++;
    while(!q.empty()){
        P p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = p.first+dic[i][0];
            int y = p.second+dic[i][1];
            if(x>=0&&x<h&&y>=0&&y<w&&s[x][y]=='.'){
                cnt++;
                s[x][y] = '#';
                q.push(make_pair(x,y));
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
    while(cin>>w>>h&&!(w==0&&h==0)){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> s[i][j];
                if(s[i][j]=='@'){
                    a = i;
                    b = j;
                }
            }
        }
        cnt = 0;
        bfs();
        cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1979