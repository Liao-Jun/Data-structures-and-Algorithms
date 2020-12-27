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
string s;
int a[10+10];

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
    cin >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << s;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cout << " 0";
            continue;
        }
        cout << ' ';
        cout << 0;
        cout << a[i]/(60*60);
        cout << ':';
        a[i]=a[i]%(60*60);
        if(a[i]/60<10) cout << 0 << a[i]/60;
        else cout << a[i]/60;
        cout << ':';
        a[i]=a[i]%60;
        if(a[i]<10) cout << 0 << a[i];
        else cout << a[i];
    }
    cout << endl;

    return 0;
}