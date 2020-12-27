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
const int M = 1e3+10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n,m;
    cin >> n;
    int a[M];
    int b;
    memset(a,0,sizeof(a));
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    sort(a+1,a+n+1);
    int flag = 0;
    for(int i=0;i<m;i++){
        cin >> b;
        int x = a[n];
        if(5*(x-a[b])<=sum&&a[b]>=1){
            sum--;
            a[b]--;
            sort(a+1,a+n+1);
        }else{
            flag = 1;
            break;
        }
    }
    if(flag==1) cout << "BUG\n";
    else cout << "PASS\n";

    return 0;
}