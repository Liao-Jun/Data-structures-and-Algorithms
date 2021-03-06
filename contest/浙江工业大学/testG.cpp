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
    cin >> n >> m;        
    if(m==0){
        cout << "0.000000" << endl;
    }else{
        double sum = 0;
        int t = n+1;
        int cnt = 1;
        while(t--){
            int x = cnt;
            double y = 1;
            int N = n;
            int M = m;
            int S = n+m;
            while(x>1){
                y *= double(N)/double(S);
                N--;
                S--;
                x--;
            }
            // cout << y << endl;
            y *= double(M)/double(S);
            // cout << y << endl;
            sum += cnt*y;
            // cout << sum << endl;
            cnt++;
        }
        printf("%.6lf\n",sum);
    }

    return 0;
}