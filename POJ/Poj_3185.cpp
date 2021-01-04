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
int a[25],b[25];
int cal(int k){
    memcpy(b,a,sizeof(a));
    b[0] ^= k;
    b[1] ^= k;
    int sum = k;
    for(int i=0;i<19;i++){
        if(b[i]==1){
            b[i+1] ^= 1;
            if(i+2<20) b[i+2] ^= 1;
            sum++;
        }
    }
    if(b[19]==0) return sum;
    else return INF;
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
    for(int i=0;i<20;i++){
        cin >> a[i];
    }
    cout << min(cal(0),cal(1)) << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-3185