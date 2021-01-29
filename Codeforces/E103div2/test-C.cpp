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
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
// #define endl '\n'
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
const int M = 1e5+10;
ll c[M],a[M],b[M];
int n;

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
            cin >> c[i];
        }
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        ll Max = 0;
        ll f = 0;
        for(int i=1;i<n;i++){
            if(b[i]>=a[i]){
                Max = max(Max,b[i]-a[i]+c[i]+1);
                // cout << Max;
                if(b[i]==a[i]) f = 0;
                if(b[i]!=a[i]){
                    if(f!=0){
                        f = f-(b[i]-a[i])+1+c[i];
                        Max = max(Max,f);
                    }
                }
                if(f==0){
                    f = b[i]-a[i]+c[i]+1;
                }
                // cout << ' ' << Max << ' ' << f << endl;
            }else{
                swap(b[i],a[i]);
                Max = max(Max,b[i]-a[i]+c[i]+1);
                // cout << Max;
                if(b[i]==a[i]) f = 0;
                if(b[i]!=a[i]){
                    if(f!=0){
                        f = f-(b[i]-a[i])+1+c[i];
                        Max = max(Max,f);
                    }
                }
                if(f==0){
                    f = b[i]-a[i]+c[i]+1;
                }
                // cout << ' ' << Max << ' ' << f << endl;
            }
        }
        cout << Max << endl;
    }

    return 0;
}