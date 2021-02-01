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
int a[105][105];
int dic[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

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
    int count = 2;
    int d[] = {m-1,n-1,0,1};
    int flag = 0;
    int x = 0, y = 0;
    a[x][y] = 1;
    while(count<=n*m){
        if(flag==0){
            while(y<d[0]){
                y++;
                a[x][y] = count++;
            }
            d[0]--;
            flag = 1;
        }else if(flag==1){
            while(x<d[1]){
                x++;
                a[x][y] = count++;
            }
            d[1]--;
            flag = 2;
        }else if(flag==2){
            while(y>d[2]){
                y--;
                a[x][y] = count++;
            }
            d[2]++;
            flag = 3;
        }else if(flag==3){
            while(x>d[3]){
                x--;
                a[x][y] = count++;
            }
            d[3]++;
            flag = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j];
            if(j==m-1) cout << endl;
            else cout << ' ';
        }
    }

    return 0;
}