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
    cin >> s1 >> s2;
    int a[105];
    memset(a,0,sizeof(a));
    int cnt = 0;
    for(int i=0;i<s1.length()-1;i++){
        if(s1[i]!=s2[i]&&a[i]%2==0){
            a[i] ++;
            a[i+1] ++;
        }else if(s1[i]==s2[i]&&a[i]%2==1){
            a[i] ++;
            a[i+1] ++;
        }
        cnt += a[i];
    }
    cout << cnt/2 << endl;

    return 0;
}