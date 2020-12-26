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
// inline ll gcd(ll x, ll y){if(!y) return x;return gcd(y,y%x);}
inline void debug(){printf("@@\n");}
const int M = 2e5+10;
int a[M];
int b[] = {1,1,4,5,1,4};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n;
    int cnt = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i+5<n;i++){
        if(i<=4){
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]&&a[i+3]==b[3]&&a[i+4]==b[4]&&a[i+5]==b[5]){
                a[i] = 4;
                i = i+6;
            }
        }else{
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]&&a[i+3]==b[3]&&a[i+4]==b[4]&&a[i+5]==b[5]){
                if(a[i-1]==b[4]&&a[i-2]==b[3]&&a[i-3]==b[2]&&a[i-4]==b[1]&&a[i-5]==b[0]){
                    a[i] = 5;
                    i = i+6;
                }else{
                    a[i] = 4;
                    i = i+6;
                }
            }
        }
    }
    for(int i=0;i+5<n;i++){
        if(i<=4){
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]&&a[i+3]==b[3]&&a[i+4]==b[4]&&a[i+5]==b[5]){
                a[i] = 4;
                i = i+6;
            }
        }else{
            if(a[i]==b[0]&&a[i+1]==b[1]&&a[i+2]==b[2]&&a[i+3]==b[3]&&a[i+4]==b[4]&&a[i+5]==b[5]){
                if(a[i-1]==b[4]&&a[i-2]==b[3]&&a[i-3]==b[2]&&a[i-4]==b[1]&&a[i-5]==b[0]){
                    a[i] = 5;
                    i = i+6;
                }else{
                    a[i] = 4;
                    i = i+6;
                }
            }
        }
    }
    cout << a[0];
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
    cout << endl;

    return 0;
}