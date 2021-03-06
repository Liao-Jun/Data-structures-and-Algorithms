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
#include <time.h>
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
int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum = INF;
    for(int i=1;i<=83;++i){
        int l = i, r = i+17;
        int res = 0;
        for(int j=0;j<n;++j){
            if(a[j]<l) res += (l-a[j])*(l-a[j]);
            else if(a[j]>r) res += (a[j]-r)*(a[j]-r);
        }
        sum = min(sum,res);
    }
    cout << sum << endl;

    return 0;
}