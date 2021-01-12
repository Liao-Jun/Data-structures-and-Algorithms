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
int s,n,m;
int used[105][105][105];
struct node{
    int a,b,c;
    int step;
    node(int _a, int _b, int _c, int _step){
        a = _a;
        b = _b;
        c = _c;
        step = _step;
    }
};
int bfs(){
    queue<node> q;
    q.push(node(s,0,0,0));
    used[s][0][0] = 1;
    while(!q.empty()){
        node N = q.front();
        q.pop();
        if(N.a==(s/2)&&(N.b==(s/2)||N.c==(s/2))){
            return N.step;
        }
        if(N.a>N.b){
            int a = N.a;
            int b = 0;
            if(N.a>=n){
                a -= n;
                b = n;
            }else if(N.a<n){
                a = 0;
                b = N.a;
            }
            if(used[a][b][N.c]==0){
                q.push(node(a,b,N.c,N.step+1));
                used[a][b][N.c] = 1;
            }
        }
        if(N.a>N.c){
            int a = N.a;
            int c = 0;
            if(N.a>=m){
                a -= m;
                c = m;
            }else if(N.a<m){
                a = 0;
                c == N.a;
            }
            if(used[a][N.b][c]==0){
                q.push(node(a,N.b,c,N.step+1));
                used[a][N.b][c] = 1;
            }
        }
        if(N.b>0){
            int a = N.a+N.b;
            int b = 0;
            if(used[a][b][N.c]==0){
                q.push(node(a,b,N.c,N.step+1));
                used[a][b][N.c] = 1;
            }
        }
        if(N.b>0&&N.c<m){
            int b = N.b;
            int c = N.c;
            if(N.b+N.c>=m){
                c = m;
                b = N.b-(m-N.c);
            }else if(N.b+N.c<m){
                c = N.b+N.c;
                b = 0;
            }
            if(used[N.a][b][c]==0){
                q.push(node(N.a,b,c,N.step+1));
                used[N.a][b][c] = 1;
            }
        }
        if(N.c>0){
            int a = N.a+N.c;
            int c = 0;
            if(used[a][N.b][c]==0){
                q.push(node(a,N.b,c,N.step+1));
                used[a][N.b][c] = 1;
            }
        }
        if(N.c>0&&N.b<n){
            int b = 0;
            int c = 0;
            if(N.c+N.b>=n){
                b = n;
                c = N.c-(n-N.b);
            }else if(N.c+N.b<n){
                c = 0;
                b = N.c+N.b;
            }
            if(used[N.a][b][c]==0){
                q.push(node(N.a,b,c,N.step+1));
                used[N.a][b][c] = 1;
            }
        }
    }
    return 0;
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
    while(cin>>s>>n>>m&&!(s==0&&n==0&m==0)){
        memset(used,0,sizeof(used));
        int cnt = bfs();
        if((s%2==1)||cnt==0) cout << "NO" << endl;
        else cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/HDU-1495