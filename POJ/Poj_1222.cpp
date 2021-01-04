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
int a[10][10];
int tmp[10][10];
int b[10][10];
int dic[5][2] = {{0,0},{1,0},{-1,0},{0,-1},{0,1}};
int check(int x, int y){
    int sum = a[x][y];
    for(int i=0;i<5;i++){
        int x11 = x+dic[i][0];
        int y11 = y+dic[i][1];
        if(x11>=0&&x11<5&&y11>=0&&y11<6){
            sum += tmp[x11][y11];
        }
    }
    return sum%2;
}

int cal(){
    for(int i=1;i<5;i++){
        for(int j=0;j<6;j++){
            if(check(i-1,j)==1){
                tmp[i][j] = 1;
            }
        }
    }
    for(int i=0;i<6;i++){
        if(check(4,i)==1) return INF;
    }
    int res = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            if(tmp[i][j]==1) res++;
        }
    }
    return res;
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
    int cnt = 0;
    while(t--){
        memset(a,0,sizeof(a));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                cin >> a[i][j];
            }
        }
        int ans = INF;
        for(int i=0;i<(1<<6);i++){
            memset(tmp,0,sizeof(tmp));
            for(int j=0;j<6;j++){
                tmp[0][j] = i>>j&1;
            }
            int num = cal();
            if(num<ans){
                ans = num;
                for(int j=0;j<5;j++){
                    for(int k=0;k<6;k++){
                        b[j][k] = tmp[j][k];
                    }
                }
            }
        }
        cout << "PUZZLE #" << ++cnt << endl;
        for(int i=0;i<5;i++){
            cout << b[i][0];
            for(int j=1;j<6;j++){
                cout << ' ' << b[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1222