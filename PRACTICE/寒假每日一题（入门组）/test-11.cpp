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
int n,m;
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
    memset(a,0,sizeof(a));
    cin >> n >> m;
    int t;
    for(int i=0;i<n;i++){
        cin >> t;
        if(t<=1000) a[t] ++;
    }
    int flag = 1;
    for(int i=1;i<m;i++){
        if(a[i]>0){
            if(i==m-i){
                if(a[i]>=2){
                    cout << i << ' ' << i << endl;
                    flag = 0;
                    break;
                }
            }else if(a[m-i]>0){
                cout << i << ' ' << m-i << endl;
                flag = 0;
                break;
            }
        }
    }
    if(flag) cout << "No Solution\n";

    return 0;
}