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
const int M = 1e5+10;
ll n,x;
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
    cin >> t;
    while(t--){
        cin >> n >> x;
        int Min = INF;
        int point = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ll y = a[i];
            int cnt = 1;
            while(y%x==0){
                cnt++;
                y /= x;
            }
            if(Min>cnt){
                Min = cnt;
                point = i;
            }
        }
        for(int i=0;i<n;i++){
            if(i<point){
                sum += (a[i]*(Min+1));
            }else{
                sum += (a[i]*(Min));
            }
        }
        cout << sum << endl;
    }

    return 0;
}