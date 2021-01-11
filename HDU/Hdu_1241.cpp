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
char s[105][105];
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
void bfs(int x, int y){
    queue<P> q;
    q.push(make_pair(x,y));
    s[x][y] = '*';
    while(!q.empty()){
        P p = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int x = p.first+dic[i][0];
            int y = p.second+dic[i][1];
            if(x>=0&&x<m&&y>=0&&y<n&&s[x][y]=='@'){
                q.push(make_pair(x,y));
                s[x][y] = '*';
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
    while(cin >> m >> n && m!=0){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> s[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='@'){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/HDU-1241