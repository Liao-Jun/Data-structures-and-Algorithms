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
ll dic[20];
ll s[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    dic[1] = 1;
    s[1] = 1;
    for(int i=2;i<=15;i++){
        dic[i] = 1ll*2*dic[i-1];
        s[i] = s[i-1]+dic[i];
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int flag = 0;
        for(int i=2;i<=15;i++){
            if(n%s[i]==0){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "YE5" << endl;
        else cout << "N0" << endl;
    }

    return 0;
}