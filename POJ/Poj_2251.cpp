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
int l,r,c;
string s[35][35];
int used[35][35][35];
int dic[][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node{
    int x;
    int y;
    int z;
    int step;
    node(int _z,int _x,int _y,int _step=0){
        z = _z;
        x = _x;
        y = _y;
        step = _step;
    }
};
int bfs(){
    int x22,y22,z22;
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                if(s[i][j][k]=='S'){
                    z22 = i;
                    x22 = j;
                    y22 = k;
                    break;
                }
            }
        }
    }
    node N = node(z22,x22,y22,0);
    queue<node> q;
    q.push(N);
    while(!q.empty()){
        node N = q.front();
        q.pop();
        // cout << N.z << ' ' << N.x << ' ' << N.y << '@' << endl;//debug
        for(int i=0;i<6;i++){
            int x11 = N.x;
            int y11 = N.y;
            int z11 = N.z;
            int step1 = N.step;
            x11 += dic[i][0];
            y11 += dic[i][1];
            z11 += dic[i][2];
            if(z11>=0&&z11<l&&x11>=0&&x11<r&&y11>=0&&y11<c&&s[z11][x11][y11]=='E'&&used[z11][x11][y11]==0){
                return step1+1;
            }
            if(z11>=0&&z11<l&&x11>=0&&x11<r&&y11>=0&&y11<c&&s[z11][x11][y11]=='.'&&used[z11][x11][y11]==0){
                q.push(node(z11,x11,y11,step1+1));
                used[z11][x11][y11] = 1;
            }
        }
    }
    if(q.empty()){
        return INF;
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
    while(cin>>l>>r>>c&&!(l==0&&r==0&&c==0)){
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                cin >> s[i][j];
            }
        }
        memset(used,0,sizeof(used));
        int cnt = bfs();
        if(cnt==INF) cout << "Trapped!" << endl;
        else cout << "Escaped in " << cnt << " minute(s)." << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-2251