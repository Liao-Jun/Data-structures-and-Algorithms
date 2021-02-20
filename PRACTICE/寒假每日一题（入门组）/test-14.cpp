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
int n,num = 0;;
vector<int> path;
int x[3][100];
void dfs(int a){
    if(a>n){
        if(++num<=3){
            for(auto it:path) cout << it << ' ';
            cout << endl;
        }
        return;
    }else{
        for(int i=1;i<=n;i++){
            if(x[0][i]==0&&x[1][i-a+n]==0&&x[2][a+i]==0){
                x[0][i] = 1;
                x[1][i-a+n] = 1;
                x[2][a+i] = 1;
                path.push_back(i);
                dfs(a+1);
                x[0][i] = 0;
                x[1][i-a+n] = 0;
                x[2][a+i] = 0;
                path.pop_back();
            }
        }
    }
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
    memset(x,0,sizeof(x));
    cin >> n;
    dfs(1);
    cout << num << endl;

    return 0;
}