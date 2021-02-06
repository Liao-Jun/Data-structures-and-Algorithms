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
int x,y;
string s;
map<char,int> m;
char dic_c[] = "UDRL";

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
        cin >> x >> y >> s;
        m.clear();
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        if(y>0) m[dic_c[0]] -= y;
        if(y<0) m[dic_c[1]] += y;
        if(x>0) m[dic_c[2]] -= x;
        if(x<0) m[dic_c[3]] += x;
        int flag = 1;
        for(auto it:m){
            if(it.second<0){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}