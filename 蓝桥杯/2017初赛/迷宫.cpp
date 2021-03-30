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
#include <time.h>
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
int dic[][2] = {{0,1},{-1,0},{1,0},{0,-1}};
map<char,int> dic_char= {{'R',0},{'U',1},{'D',2},{'L',3}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    // string s[15];
    // for(int i=0;i<10;i++){
    //     cin >> s[i];
    // }
    // int a[15][15];
    // memset(a,0,sizeof(a));
    // int t = 20;
    // while (t --){
    //     for(int i=0;i<10;i++){
    //         for(int j=0;j<10;j++){
    //             int x = i+dic[dic_char[s[i][j]]][0];
    //             int y = j+dic[dic_char[s[i][j]]][1];
    //             if(x<0||y<0||x>9||y>9||a[x][y]==1) a[i][j] = 1;
    //         }
    //     }
    // }
    // int cnt = 0;
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         if(a[i][j] == 1) cnt ++;
    //     }
    // }
    // cout << cnt;
    cout << 31 << endl;

    return 0;
}