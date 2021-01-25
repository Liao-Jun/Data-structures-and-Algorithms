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
const int M = 1e6+10;
ull s[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    set<ull> se;
    se.clear();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%ulld",&s[i]);
        se.insert(s[i]);
    }
    map<ull,int> dic;
    dic.clear();
    int cnt = n;
    int f = 0, t = 0, res = 0;
    while(1){
        while(f<n&&res<se.size()){
            if(dic[s[f]]==0){
                res++;
            }
            dic[s[f]]++;
            f++;
        }
        if(res<se.size()) break;
        cnt = min(cnt,f-t);
        if(dic[s[t]]==1){
            res--;
        }
        dic[s[t]]--;
        t++;
    }
    cout << cnt << '\n';

    return 0;
}