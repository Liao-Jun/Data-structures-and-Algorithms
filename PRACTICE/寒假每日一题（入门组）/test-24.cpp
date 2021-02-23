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
int n;
int a[40][40];
bool ju[40];
bool check_1(){
    for(int i=0;i<n*n;i++){
        memset(ju,false,sizeof(ju));
        for(int j=0;j<n*n;j++){
            if(a[i][j]<=0||a[i][j]>n*n) return false;
            if(ju[a[i][j]]) return false;
            ju[a[i][j]] = true;
        }
    }
    return true;
}

bool check_2(){
    for(int i=0;i<n*n;i++){
        memset(ju,false,sizeof(ju));
        for(int j=0;j<n*n;j++){
            if(a[j][i]<=0||a[j][i]>n*n) return false;
            if(ju[a[j][i]]) return false;
            ju[a[j][i]] = true;
        }
    }
    return true;
}

bool check_3(){
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++){
            if(i%n==0&&j%n==0){
                memset(ju,false,sizeof(ju));
                for(int dx=0;dx<n;dx++){
                    for(int dy=0;dy<n;dy++){
                        if(a[i+dx][j+dy]<=0||a[i+dx][dy+j]>n*n) return false;
                        if(ju[a[i+dx][j+dy]]) return false;
                        ju[a[i+dx][j+dy]] = true;
                    }
                }
            }
        }
    }
    return true;
}

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
    int cnt = 1;
    while(t--){
        cin >> n;
        for(int i=0;i<n*n;i++){
            for(int j=0;j<n*n;j++){
                cin >> a[i][j];
            }
        }
        if(check_1()&&check_2()&&check_3()) cout << "Case #" << cnt++ << ": Yes" << endl;
        else cout << "Case #" << cnt++ << ": No" << endl;
    }

    return 0;
}