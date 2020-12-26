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
int f[100];

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
        if(i%8==0){
            f[cnt++] = i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a[10];
        int sum = 0;
        for(int i=0;i<10;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum==0) cout << -1 << endl;
        else if(sum==1){
            if(a[8]==1) cout << 8 << endl;
        }else if(sum==2){
            int num = 0;
            if(a[8]==2) cout << 88 << endl;
            else{
                for(int i=9;i>=0;i--){
                    if(a[i]==1) num = num*10+i;
                }
                if(num%8==0) cout << num << endl;
                else{
                    num = 0;
                    for(int i=0;i<10;i++){
                        if(a[i]==1) num = num*10+i;
                    }
                    if(num%8==0) cout << num << endl;
                    else cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}