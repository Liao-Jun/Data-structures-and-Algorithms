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
int a,b,c;
int used[105][105];
struct Node{
    int x,y;
    int id;
};
Node pre[105][105];
string dic[6] = {{"FILL(1)"},{"FILL(2)"},{"POUR(2,1)"},{"POUR(1,2)"},{"DROP(1)"},{"DROP(2)"}};
struct node{
    int a,b;
    int step;
    node(int _a, int _b, int _step){
        a = _a;
        b = _b;
        step = _step;
    }
};
vector<int> v;
int bfs(){
    queue<node> q;
    q.push(node(0,0,0));
    used[0][0] = 0;
    while(!q.empty()){
        node N = q.front();
        q.pop();
        if(N.a==c||N.b==c){
            int x = N.a;
            int y = N.b;
            while(!(x==0&&y==0)){
                v.push_back(pre[x][y].id);
                int x11 = x;
                int y11 = y;
                x = pre[x11][y11].x;
                y = pre[x11][y11].y;
            }
            return N.step;
        }
        if(N.a<a){
            int a11 = a;
            int b11 = N.b;
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 0;
            }
        }
        if(N.b<b){
            int a11 = N.a;
            int b11 = b;
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 1;
            }
        }
        if(N.a>0){
            int a11 = 0;
            int b11 = N.b;
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 4;
            }
        }
        if(N.b>0){
            int a11 = N.a;
            int b11 = 0;
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 5;
            }
        }
        if(N.a>0&&N.b<b){
            int a11 = 0;
            int b11 = 0;
            if(N.a+N.b>=b){
                b11 = b;
                a11 = N.a-(b-N.b);
            }else if(N.a+N.b<b){
                b11 = N.a+N.b;
                a11 = 0;
            }
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 3;
            }
        }
        if(N.b>0&&N.a<a){
            int a11 = 0;
            int b11 = 0;
            if(N.a+N.b>=a){
                a11 = a;
                b11 = N.b-(a-N.a);
            }else if(N.a+N.b<a){
                a11 = N.a+N.b;
                b11 = 0;
            }
            if(used[a11][b11]==0){
                q.push(node(a11,b11,N.step+1));
                used[a11][b11] = 1;
                pre[a11][b11].x = N.a;
                pre[a11][b11].y = N.b;
                pre[a11][b11].id = 2;
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
    cin >> a >> b >> c;
    memset(used,0,sizeof(used));
    int cnt = bfs();
    if(cnt==0&&c!=0) cout << "impossible" << endl;
    else{
        cout << cnt << endl;
        while(v.size()){
            cout << dic[v.back()] << endl;
            v.pop_back();
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3414