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
// typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
struct node{
    double left,right;
};
node P[1005];
bool cmp(const node &a, const node &b){
    return a.right < b.right;
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
    int n,d;
    int res = 0;
    while(cin>>n>>d&&(n!=0&&d!=0)){
        int a,b;
        int ok = 1;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            if(b>d) ok = -1;
            P[i].left = a-sqrt(d*d-b*b);
            P[i].right = a+sqrt(d*d-b*b);
        }
        if(ok==-1){
            cout << "Case " << ++res << ": " << -1 << endl;
            continue;
        }
        sort(P,P+n,cmp);
        int cnt = 1;
        double x = P[0].right;
        for(int i=1;i<n;i++){
            if(P[i].left<=x&&P[i].right>=x) continue;
            else{
                x = P[i].right;
                cnt++;
            }
        }
        cout << "Case " << ++res << ": " << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1328