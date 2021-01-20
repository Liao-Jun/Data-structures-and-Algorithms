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
int s[15],L[10],R[10];
int flag;
void dfs(int x, int l, int r){
    if(x>=10){
        flag = 1;
        return;
    }
    if(flag) return;
    if(s[x]>L[l-1]){
        L[l] = s[x];
        dfs(x+1,l+1,r);
    }
    if(s[x]>R[r-1]){
        R[r] = s[x];
        dfs(x+1,l,r+1);
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
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<10;i++){
            cin >> s[i];
        }
        flag = 0;
        L[0] = 0;
        R[0] = 0;
        dfs(0,1,1);
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

//https://vjudge.net/problem/Aizu-0033