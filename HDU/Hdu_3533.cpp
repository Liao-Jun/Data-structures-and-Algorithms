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
const int dic[][2] = {{1,0},{0,1},{0,0},{-1,0},{0,-1}};
map<char,int> dic_char = {{'N',3},{'S',0},{'W',4},{'E',1}};
int m,n,k,d;
struct node{
    int t,v,x,y;
    char c;
    node(int _t = 0, int _v = 0, int _x = 0, int _y = 0, char _c = '0'){
        t = _t;
        v = _v;
        x = _x;
        y = _y;
        c = _c;
    }
};
struct Node{
    int x,y;
    int step;
    Node(int _x, int _y, int _step){
        x = _x;
        y = _y;
        step = _step;
    }
};
node cas[105];
set<P> se[105];
void update(int time){
    for(int i=0;i<k;i++){
        int C = cas[i].c;
        int D = dic_char[C];
        for(auto it=se[i].begin();it!=se[i].end();++it){
            int x = it->first;
            x += dic[D][0]*cas[i].v;
            int y = it->second;
            y += dic[D][1]*cas[i].v;
            se[i].erase(it);
            if(x<=m&&y<=n) se[i].insert(make_pair(x,y));
        }
        if(time%cas[i].t==0){
            int x = cas[i].x+dic[D][0]*cas[i].v;
            int y = cas[i].y+dic[D][1]*cas[i].v;
            se[i].insert(make_pair(x,y));
        }
    }
}

bool check(int x, int y){
    P p = make_pair(x,y);
    for(int i=0;i<k;i++){
        if(se[i].find(p)!=se[i].end()) return false;
    }
    return true;
}

int bfs(){
    queue<Node> q;
    while(!q.empty()){
        Node N = q.front();
        q.pop();
        if(!check(N.x,N.y)) continue;
        for(int i=0;i<5;i++){
            int x = N.x+dic[i][0];
            int y = N.y+dic[i][1];
            if(x>=0&&x<=m&&y>=0&&y<=n){
                if(x==m&&y==n) return N.step+1;
                q.push(Node(x,y,N.step+1));
            }
        }
        update(N.step+1);
    }
    return INF;
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
    while(cin>>m>>n>>k>>d){
        for(int i=0;i<k;i++){
            cin >> cas[i].c >> cas[i].t >> cas[i].v >> cas[i].x >> cas[i].y;
        }
        int cnt = bfs();
        cout << cnt << endl;
    }

    return 0;
}