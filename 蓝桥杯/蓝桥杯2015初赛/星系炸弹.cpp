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
int dic[][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
bool check(int n){
    if(n%100==0) return false;
    if(n%4==0) return true;
    return false;
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
    int a,b,c,n;
    while(cin >> a >> b >> c >> n){
        int flag = 0;
        while(n--){
            if(check(a)) flag = 1;
            else flag = 0;
            if(b==12){
                if(dic[b-1][flag]==c){
                    c = 1;
                    b = 1;
                    a ++;
                }else c ++;
            }else{
                if(dic[b-1][flag]==c){
                    c = 1;
                    b ++;
                }else c ++;
            }
        }
        cout << a << '-';
        if(b<10) cout << 0 << b;
        else cout << b;
        cout << '-';
        if(c<10) cout << 0 << c;
        else cout << c;
        cout << endl;
    }

    return 0;
}

//http://oj.ecustacm.cn/problem.php?id=1251