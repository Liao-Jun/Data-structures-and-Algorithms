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
int n;
string s[M];
int pre[M];
int f[M];

void init(int x){
    memset(f,-1,sizeof(f));
    for(int i=0;i<x;i++){
        pre[i] = i;
    }
}

int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
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
    while(t--){
        cin >> n;
        init(n);
        for(int i=0;i<n;i++){
            cin >> s[i];
            for(int j=0;j<s[i].length();j++){
                int y = s[i][j]-'0';
                if(f[y]==-1) f[y] = i;
                else{
                    int fa = find_root(i);
                    int fb = find_root(f[y]);
                    if(fa!=fb){
                        pre[fa] = fb;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(pre[i]==i) cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}