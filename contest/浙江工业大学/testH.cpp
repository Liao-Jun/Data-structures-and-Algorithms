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
const int M = 1e5+10;
int c1,k1,c2,k2;
int n,m;
struct node{
    int a,d;
    int cnt;
};
bool cmp(const node &a, const node &b){
    return a.cnt < b.cnt;
}
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> c1 >> k1 >> c2 >> k2;
        for(int i=0;i<n;i++){
            cin >> N[i].a;
        }
        for(int i=0;i<n;i++){
            cin >> N[i].d;
            int k = c1 - N[i].d*k1;
            if(k>0) N[i].cnt = (N[i].a+k-1)/k;
            else N[i].cnt = INF;
            k = c2 - N[i].d*k2;
            if(k>0){
                int y = (N[i].a+k-1)/k;
                N[i].cnt = min(N[i].cnt,y);
            }
        }
        sort(N,N+n,cmp);
        int cnt = 0;
        while(1){
            if(cnt<n&&m>=N[cnt].cnt){
                cnt++;
                m -= N[cnt-1].cnt;
                if(m==0){
                    break;
                }
            }else{
                break;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}