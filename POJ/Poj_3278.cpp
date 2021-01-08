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
const int M = 2e5+5;
int n,k;
int used[M];
int b[M];
int bfs(){
    queue<int> q;
    q.push(n);
    // used[n] = 1;
    b[n] = 0;
    while(!q.empty()){
        int a1 = q.front();
        q.pop();
        int cnt = b[a1];
        if(a1==k) break;
        for(int i=0;i<3;i++){
            int a = a1;
            if(i==0) a -= 1;
            if(i==1) a += 1;
            if(i==2) a *= 2;
            if(a>0&&a<2*k&&used[a]==0){
                q.push(a);
                used[a] = 1;
                b[a] = cnt+1;
            }
        }
    }
    return b[k];
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
    cin >> n >> k;
    memset(used,0,sizeof(used));
    memset(b,0,sizeof(b));
    if(n>k) cout << n-k << endl;
    else cout << bfs() << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-3278