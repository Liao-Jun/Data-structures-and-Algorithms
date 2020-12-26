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
// #define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
inline int gcd(int x, int y){if(y==0) return x;return gcd(y,x%y);}
inline void debug(){printf("@@\n");}
int mpow(int b,int p){
    int res = 1;
    while(p>0){
        if(p&1) res=res*b;
        b = b*b;
        p>>=1;
    }
    return res;
}

int q_mul(int a, int b){
    int res;
    while(b>0){
        if(b&1) res += a;
        a = (a*2);
        b>>=1;
    }
    return res;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int a,b,n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&n);
        double x,y;
        int flag;
        double sum = -INF;
        for(int i=0;i<=n;i++){
            x = a*i+b;
            y = mpow(2,i);
            double s = x/y;
            if(s>sum){
                flag = i;
                sum = s;
            }
        }
        int X, Y;
        X = a*flag+b;
        Y = mpow(2,flag);
        if(X%Y==0) printf("%d\n",X/Y);
        else{
            if(X<0){
                int x1 = abs(X)/(gcd(max(abs(X),Y),min(abs(X),Y)));
                int y1 = Y/(gcd(max(abs(X),Y),min(abs(X),Y)));
                printf("-%d/%d\n",x1,y1);
            }else{
                int x1 = abs(X)/(gcd(max(abs(X),Y),min(abs(X),Y)));
                int y1 = Y/(gcd(max(abs(X),Y),min(abs(X),Y)));
                printf("%d/%d\n",x1,y1);
            }
        } 
    }

    return 0;
}