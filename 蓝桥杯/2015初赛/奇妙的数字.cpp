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
set<int> se;
bool check(int x){
    map<int,int> dic;
    int a = x*x;
    while(a>9){
        dic[a%10]++;
        a/=10;
    }
    dic[a]++;
    a = x*x*x;
    while(a>9){
        dic[a%10]++;
        a/=10;
    }
    dic[a]++;
    for(auto it:se){
        if(dic[it]!=1) return false;
    }
    return true;
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
    for(int i=0;i<=9;i++){
        se.insert(i);
    }
    for(int i=1;;i++){
        if(check(i)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}

//http://oj.ecustacm.cn/problem.php?id=1252