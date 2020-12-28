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
const int M = 105;
string s[M];
int dic[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int used[105][105];

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
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                used[i][j] = 0;
                cout << used[i][j] << ' ';
            }
            cout << endl;
        }
        // debug();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='#'){
                    for(int k=0;k<4;k++){
                        int I = i+dic[k][0];
                        int J = j+dic[k][1];
                        if(s[I][J]=='*'&&I>=0&&I<n&&J>=0&&J<m){
                            used[I][J]++;
                            // cout << I <<' ' << J << endl;
                        }
                    }
                }
            }
        }
        vector<P> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(used[i][j]>1){
                    v.push_back(make_pair(i+1,j+1));
                }
            }
        }
        if(v.size()==0) cout << -1 << endl;
        else{
            for(auto it=v.begin();it!=v.end();++it){
                cout << it->first << ' ' << it->second << endl;
            }
        }
    }

    return 0;
}