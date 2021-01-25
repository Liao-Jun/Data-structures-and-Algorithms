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
#include <unordered_map>
#include <unordered_set>
#include <sstream>
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
int x,y,x11,y11;
string s;
int dic[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
struct node{
    int x,y;
    int d;
    int i;
    node(int _x, int _y, int _d, int _i){
        i = _i;
        d = _d;
        x = _x;
        y = _y;
    }
};
bool check(){
    queue<node> q;
    q.push(node(0,0,1,0));
    while(!q.empty()){
        node N = q.front();
        q.pop();
        if(N.x==x&&N.y==y&&N.i==s.length()) return true;
        if(N.i>s.length()) return false;
        if(s[N.i]=='F'){
            int x11 = N.x+dic[N.d][0];
            int y11 = N.y+dic[N.d][1];
            q.push(node(x11,y11,N.d,N.i+1));
        }else{
            q.push(node(N.x,N.y,(N.d+1)%4,N.i+1));
            q.push(node(N.x,N.y,(N.d-1)%4,N.i+1));
        }
    }
    return false;
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
    cin >> s;
    cin >> x >> y;
    x11 = 0;
    y11 = 0;
    if(check()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}