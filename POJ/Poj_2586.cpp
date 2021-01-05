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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    ll s,d;
    while(scanf("%lld%lld",&s,&d)!=EOF){
        ll sum = 0;
        if(4*s<d){
            sum = 10*s-2*d;
        }else if(3*s<2*d){
            sum = 8*s-4*d;
        }else if(2*s<3*d){
            sum = 6*s-6*d;
        }else if(s<4*d){
            sum = 3*s-9*d;
        }else{
            sum = -12*d;
        }
        if(sum<0){
            cout << "Deficit" << endl;
        }else{
            cout << sum << endl;
        }
    }

    return 0;
}

//https://vjudge.z180.cn/problem/POJ-2586