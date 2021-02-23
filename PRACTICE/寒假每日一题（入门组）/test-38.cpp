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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int a[105][105];
    int t;
    cin >> t;
    memset(a,0,sizeof(a));
    while(t--){
        int x11,y11,x22,y22;
        cin >> x11 >> y11 >> x22 >> y22;
        for(int i=x11;i<x22;i++){
            for(int j=y11;j<y22;j++){
                a[i][j] = 1;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(a[i][j]==1) sum++;
        }
    }
    cout << sum << endl;

    return 0;
}