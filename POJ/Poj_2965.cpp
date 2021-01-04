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
int a[5][5],tmp[5][5],b[5][5];
int check(int x, int y){
    int sum = a[x][y];
    for(int i=0;i<4;i++){
        int x11 = x;
        int y11 = i;
        sum += tmp[x11][y11];
        x11 = i;
        y11 = y;
        sum += tmp[x11][y11];
    }
    return sum%2;
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
    string s[5];
    for(int i=0;i<4;i++){
        cin >> s[i];
        for(int j=0;j<4;j++){
            if(s[i][j]=='-') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    int cnt = INF;
    for(int i=0;i<(1<<4);i++){
        memset(tmp,0,sizeof(tmp));
        int res = 0;
        for(int j=0;j<4;j++){
            tmp[0][j] = i>>j&1;
            if(tmp[0][j]==1) res++;
        }
        for(int j=1;j<4;j++){
            for(int k=0;k<4;k++){
                if(check(j,k)==1){
                    tmp[j][k] = 1;
                    res++;
                }
            }
        }
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(check(j,k)==1){
                    res = INF;
                }
            }
        }
        if(res<cnt){
            cnt = res;
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    b[i][j] = tmp[i][j];
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(b[i][j]==1) cout << i+1 << ' ' << j+1 << endl;
        }
    }

    return 0;
}