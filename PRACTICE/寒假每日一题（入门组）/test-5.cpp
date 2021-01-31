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
int b;
string dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string change(int x){
    string s;
    while(x>=b){
        s = s + dic[x%b];
        x/=b;
    }
    s = s + dic[x];
    reverse(s.begin(),s.end());
    return s;
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
    cin >> b;
    for(int i=1;i<=300;i++){
        string s = change(i*i);
        string s1 = s;
        reverse(s1.begin(),s1.end());
        if(s1==s){
            string s2 = change(i);
            cout << s2 << ' ' << s << endl;
        }
    }

    return 0;
}