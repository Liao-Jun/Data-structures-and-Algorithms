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
 
inline __int128 read(){
    __int128 x = 0 , f = 1 ;
    char ch = getchar() ;
    while(ch < '0' || ch > '9'){//使用while的原因是以防回车造成影响
        if(ch == '-'){
            f  = -f ;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x*f;
}
inline void print(__int128 x){
    if(x < 0){
        x = -x ;
        putchar('-');
    }
    if(x > 9){
        print(x/10);
    }
    putchar(x%10+'0');
     
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
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        __int128 i = 4;
        __int128 num = 1;
        if(n==0){
            printf("0\n");
            continue;
        }else if(n==1){
            printf("1\n");
            continue;
        }
        while(i<n){
            num += (i-1+i-1+i/2-1)*i/4;
            i = i*2;
        }
        i--;
        int j = (i+1)/2;
        num += (i+i+n-j)*((n-j)+1)/2;
        if((i+1) == n) num += n/2;
        print(num);printf("\n");
    }
 
    return 0;
}