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
const int M = 2e5+10;
ll a[M];

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
    int n;
    scanf("%d",&t);
    int x = 2;
    int x1 = 2;
    int y = 3;
    int cnt = 2;
    a[0] = 0;
    a[1] = 1;
    while(t--){
        scanf("%d",&n);
        ll sum = 1;
        if(n==0) sum = 0;
        else if(n==1) sum = 1;
        else if(n<cnt) sum = a[n];
        else{
            sum = a[cnt-1];
            for(int i=cnt;i<=n;i++){
                if(i==x){
                    x1 = x;
                    x *= 2;
                    y = x1*2 -1;
                    sum += 1ll*y;
                    if(i<M-10){
                        a[cnt++] = sum;
                    }
                }else{
                    sum += 1ll*(y+i-x1);
                    if(i<M-10){
                        a[cnt++] = sum;
                    }
                }
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}