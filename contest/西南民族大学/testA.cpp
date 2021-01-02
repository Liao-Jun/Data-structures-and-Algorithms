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
int x11,x22,y11,y22;
string s[11];
int cnt1 = 0;
int cnt2 = 0;
int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
struct node{
    int x,y;
    node(int _x, int _y){
        x = _x;
        y = _y;
    }
};
void dfs(){
    queue<node> q;
    q.push(node(x11,y11));
    while(!q.empty()){
        node x = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xa = x.x+dic[i][0];
            int ya = x.y+dic[i][1];
            if(xa>=0&&xa<n&&ya>=0&&ya<m&&s[xa][ya]=='*'){
                q.push(node(xa,ya));
                s[xa][ya] = '#';
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
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(int i=0;i<s[i].length();i++){
            if(s[i][j]=='H'){
                x11 = i;
                y11 = j;
            }else if(s[i][j]=='Z'){
                x22 = i;
                y22 = j;
            }
        }
    }


    return 0;
}