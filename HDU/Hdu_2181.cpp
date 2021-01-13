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
int s[25][3];
int m,t;
int ans[25];
int used[25];
void dfs(int x, int num){
    for(int i=0;i<3;i++){
        // cout << num << ' ' << s[x][i] << '@' << endl;//debug
        if(s[x][i]==m&&num==19){
            cout << t++ << ":  ";
            for(int j=0;j<20;j++){
                cout << ans[j] << ' ';
            }
            cout << m << endl;
            return;
        }
        if(used[s[x][i]]==0){
            used[s[x][i]] = 1;
            ans[num+1] = s[x][i];
            dfs(s[x][i],num+1);
            used[s[x][i]] = 0;
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
    int a[3];
    for(int i=1;i<=20;i++){
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        s[i][0] = a[0];
        s[i][1] = a[1];        
        s[i][2] = a[2];
    }
    while(cin >> m&&m!=0){
        t = 1;
        memset(used,0,sizeof(used));
        used[m] = 1;
        memset(ans,0,sizeof(ans));
        ans[0] = m;
        dfs(m,0);
    }

    return 0;
}

//https://vjudge.net/problem/HDU-2181