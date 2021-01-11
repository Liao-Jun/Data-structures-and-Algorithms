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
ll a[3][M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int n = n1+n2+n3;
    if(n==3){
        for(int i=0;i<n;i++){
            cin >> a[0][i];
        }
        sort(a[0],a[0]+n);
        cout << a[0][2]+a[0][1]-a[0][0] << endl;
    }else{
        ll sum = 0;
        for(int i=0;i<n1;i++){
            cin >> a[0][i];
            sum += a[0][i];
        }
        for(int i=0;i<n2;i++){
            cin >> a[1][i];
            sum += a[1][i];
        }
        for(int i=0;i<n3;i++){
            cin >> a[2][i];
            sum += a[2][i];
        }
        sort(a[0],a[0]+n1);
        sort(a[1],a[1]+n2);
        sort(a[2],a[2]+n3);
        int b[10];
        b[0] = a[0][0];
        if(n2<2) b[1] = INF;
        else b[1] = a[1][1];
        b[2] = a[1][0];
        if(n1<2) b[3] = INF;
        else b[3] = a[0][1];
        if(n3<2) b[4] = INF;
        else b[4] = a[2][1];
        b[5] = a[2][0];
        sort(b,b+6);
        // cout << b[3];
        int flag = -1;
        if(n1>=2&&b[0]==a[0][0]&&b[1]==a[0][1]){
            flag = 1;
        }
        if(n2>=2&&b[0]==a[1][0]&&b[1]==a[1][1]){
            flag = 1;
        }
        if(n2>=2&&b[0]==a[2][0]&&b[1]==a[2][1]){
            flag = 1;
        }
        // cout << sum << endl;//debug
        if(flag==-1) cout << sum-2*b[0] << endl;
        else cout << sum-2*(b[0]+b[1]) << endl;
    }

    return 0;
}