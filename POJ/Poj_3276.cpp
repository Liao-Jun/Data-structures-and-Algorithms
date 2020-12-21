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
// #pragma GCC optimize("O3")
// #pragma G++ optimize("O3")
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
const int M = 5e3+10;
int n;
int dir[M];
int f[M];

int slove(int x){
    memset(f,0,sizeof(f));
    int res = 0;
    int sum = 0;
    for(int i=0;i+x-1<n;i++){
        if((dir[i]+sum)%2!=0){
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-x+1>=0){
            sum -= f[i-x+1];
        }
    }
    for(int i=n-x+1;i<n;i++){
        if((dir[i]+sum)%2!=0){
            return -1;
        }
        if(i-x+1>=0) sum -= f[i-x+1];
    }
    return res;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
   #ifdef DEBUG
       freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
       freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
   #endif
   scanf("%d",&n);
   char c;
   for(int i=0;i<n;i++){
       cin >> c;
       if(c=='F') dir[i] = 0;
       else dir[i] = 1;
   }
   int K = 1,M = n;
   for(int k=1;k<=n;k++){
       int m = slove(k);
       if(m>0&&m<M){
           K = k;
           M = m;
       }
   }
   cout << K << ' ' << M << endl;

   return 0;
}

//https://vjudge.net/problem/POJ-3276