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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    // int cnt = 0;
    // string s = "aaabbbbccccc";
    // vector<string> v;
    // do{
    //     int flag = 0;
    //     for(int i=0;i<v.size();i++){
    //         if(v[i].find(s)!=string::npos){
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag) continue;
    //     string s1 = s+s;
    //     v.push_back(s1);
    //     reverse(s1.begin(),s1.end());
    //     v.push_back(s1);
    //     cnt++;
    // }while(next_permutation(s.begin(),s.end()));
    // cout << cnt << endl;
    cout << 1170 << endl;

    return 0;
}

//http://oj.ecustacm.cn/problem.php?id=1254