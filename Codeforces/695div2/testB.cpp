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
const int M = 3e5+10;
int n;
int a[M];

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
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int cnt = 0;
        int res = 0;
        int res1 = 0;
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]){
                res1++;
                cnt++;
            }else if(a[i]<a[i-1]&&a[i]<a[i+1]){
                res1++;
                cnt++;
            }else{
                res = max(res,res1);
                res1 = 0;
            }
        }
        res = max(res,res1);
        if(res>=3) cout << cnt-3 << endl;
        else cout << cnt-res << endl;
    }

    return 0;
}