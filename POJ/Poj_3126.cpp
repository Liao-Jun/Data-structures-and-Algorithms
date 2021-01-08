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
const int M = 1e5+10;
int readint() {
    int x; scanf("%d", &x); return x;
}

bool isP[M], vis[M];
int prime[M];
int cnt = 0;
void getP() {
    fill(isP, isP + M, true);
    isP[1] = isP[0] = false;
    for(int i = 2; i < M; i++) {
        if (isP[i]) {
            if (i >= 1000 && i < 1e4) prime[cnt++] = i;  //只存[1000,9999]内的素数
            for(int j = i + i; j < M; j += i) {
                isP[j] = false;
            }
        }
    }
}

bool canChange(int a, int b) {
    int num = 0, ag, bg;
    while (a) {
        ag = a%10; a /= 10;
        bg = b%10; b /= 10;
        if (ag != bg) num++;  //统计数字不一样的位数
    }
    return num == 1;
}

struct node{
    int x, step;
};
queue<node> q;

int bfs(int a, int b) {
    memset(vis, 0, sizeof(vis));  //每次要记得初始化vis数组
    while (!q.empty()) q.pop();
    q.push(node{a, 0});
    vis[a] = true;
    node now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (now.x == b) return now.step;
        for(int i = 0; i < cnt; i++) {
            if (canChange(prime[i], now.x) && !vis[prime[i]]) {
                q.push(node{prime[i], now.step + 1});
                vis[prime[i]] = true;
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
    int t = readint();
    int a, b, ans;
    getP();
    while (t--) {
        a = readint();
        b = readint();
        ans = bfs(a, b);
        cout << ans << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3126