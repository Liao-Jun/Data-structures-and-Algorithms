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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    string s1,s2;
    cin >> s1;
    cin >> s2;
    map<char,int> m;
    for(int i=0;i<s1.length();i++){
        m[s1[i]] ++;
    }
    for(int i=0;i<s2.length();i++){
        m[s2[i]] --;
    }
    int flag = 0;
    for(auto it=m.begin();it!=m.end();++it){
        if(it->second!=0){
            flag = 1;
            break;
        }
    }
    if(flag) cout << "-_-#\n";
    else cout << "^_^\n";

    return 0;
}