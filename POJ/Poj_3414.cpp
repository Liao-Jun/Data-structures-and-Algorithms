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
string s[6] = {{"FILL(1)"},{"FILL(2"},{"DROP(1)"},{"DROP(2)"},{"POUR(1,2)"},{"POUR(2,1)"}};
struct node{
    int a,b;
    int id;
    node(int _a, int _b, int _id):a(_a),b(_b),id(_id) {}
};
int used[105][105][10];
void bfs(){
    queue<node> q;
    q.push(node(0,0,0));
    while(!q.empty()){
        node N = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            if(i==0){
                if(N.a<a&&used[N.a][N.b][0]==0){
                    q.push(node(a,0,0));
                    used[N.a][N.b][0] = 1;
                }
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
    cin >> a >> b >> c;
    memset(used,0,sizeof(used));

    return 0;
}