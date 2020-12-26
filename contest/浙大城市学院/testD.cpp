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
// inline ll gcd(ll x, ll y){if(!y) return x;return gcd(y,y%x);}
inline void debug(){printf("@@\n");}
int Judge[100];
int a[10];
int b[10];
int sum;

bool check(int x){
    memset(b,0,sizeof(b));
    int y[3];
    int X = x;
    int c = 0;
    while(X>9){
        y[c++] = (X%10);
        X /= 10;
        b[y[c-1]] ++;
    }
    y[c++] = (X);
    b[y[c-1]] ++;
    for(int i=0;i<10;i++){
        if(a[i]<b[i]) return false;
    }
    return true;
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
    int cnt = 0;
    for(int i=0;i<1000;i++){
        cin >> Judge[cnt++];
    }
    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<10;i++){
            cin >> a[i];
        }
        int flag = 0;
        for(int i=0;i<cnt;i++){
            if(check(Judge[i])){

            }
        }
    }

    return 0;
}