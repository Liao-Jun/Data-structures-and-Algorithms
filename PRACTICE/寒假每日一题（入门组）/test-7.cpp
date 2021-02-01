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
const int M = 1e5+10;
int n,k;
P p[M];
bool Judge(int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int a = p[i].first/mid;
        int b = p[i].second/mid;
        cnt += a*b;
    }
    if(cnt>=k) return true;
    else return false;
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
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
        if(p[i].first>p[i].second) swap(p[i].first,p[i].second);
    }
    int l = 0, r = 1e5;
    while(r-l>2){
        int mid = (l+r)/2;
        if(Judge(mid)) l = mid;
        else r = mid+1;
    }
    cout << l << endl;

    return 0;
}