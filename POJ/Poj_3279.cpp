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
int m,n;
int a[15+1][15+1],b[15+1][15+1],c[15+1][15+1];
int dic[5][2] = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
int update(int x, int y){
    int t = a[x][y];
    for(int i=0;i<5;i++){
        int x11 = x+dic[i][0];
        int y11 = y+dic[i][1];
        if(x11>=0&&x11<=m&&y11>=0&&y11<n){
            t += b[x11][y11];
        }
    }
    return t%2;
}

int cal(){
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(update(i-1,j)==1){
                b[i][j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(update(m-1,i)==1) return  INF;
    }
    int cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cnt += b[i][j];
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
    cin >> m >> n;
    memset(a,0,sizeof(a));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int ms = INF;
    for(int i=0;i<(1<<n);i++){
        memset(b,0,sizeof(b));
        for(int j=0;j<n;j++){
            b[0][j] = (i>>j&1);
        }
        int cnt = cal();
        if(cnt<ms){
            ms = cnt;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    c[i][j] = b[i][j];
                }
            }
        }
    }
    if(ms==INF) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=0;i<m;i++){
            cout << c[i][0];
            for(int j=1;j<n;j++){
                cout << ' ' << c[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3279