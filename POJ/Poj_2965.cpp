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
int a[5][5];
int step = INF;
int changex1[20];
int changey1[20];
int rex[20];
int rey[20];
bool check(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]%2==1) return false;
        }
    }
    return true;
}

void change(int x, int y){
    for(int i=0;i<4;i++){
        a[i][y] ^= 1;
        a[x][i] ^= 1;
    }
    a[x][y] ^= 1;
}

void dfs(int m, int s){
    if(check()){
        if(s<step){
            step = s;
            for(int i=0;i<step;i++){
                rex[i] = changex1[i];
                rey[i] = changey1[i];
            }
        }
        return;
    }
    if(m>15) return;
    int x = m/4;
    int y = m%4;
    dfs(m+1,s);
    change(x,y);
    changex1[s] = x;
    changey1[s] = y;
    dfs(m+1,s+1);
    change(x,y);
    return;
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
    for(int i=0;i<4;i++){
        string s;
        cin >> s;
        for(int j=0;j<4;j++){
            if(s[j]=='+') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    memset(changex1,0,sizeof(changex1));
    memset(changey1,0,sizeof(changey1));
    dfs(0,0);
    cout << step << endl;
    for(int i=0;i<step;i++){
        cout << rex[i]+1 << ' ' << rey[i]+1 << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-2965