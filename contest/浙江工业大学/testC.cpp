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
const int M = 5e5+10;
struct node{
    int a = 0,b = 0;
};
node N[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int k;
    cin >> k;
    string s;
    cin >> s;
    int a = 0,b = 0;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            a++;
            N[i].a = a;
            N[i].b = b;
        }else if(s[i]=='1'){
            b++;
            N[i].b = b;
            N[i].a = a;
        }
    }
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i+k<n){
                cnt += 1ll*(N[i+k].b-N[i].b);
            }else{
                cnt += 1ll*(N[n-1].b-N[i].b);
            }
        }else if(s[i]=='1'){
            if(i+k<n){
                cnt += 1ll*(N[i+k].a-N[i].a);
            }else{
                cnt += 1ll*(N[n-1].a-N[i].a);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}