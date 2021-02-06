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
int n,k;
struct node{
    int id,h;
};

struct cmp{
    bool operator()(const node &a, const node &b){
        if(a.h!=b.h){
            return a.h>b.h;
        }else{
            return a.id<b.id;
        }
    }
};

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
        cin >> n >> k;
        priority_queue<node, vector<node>, cmp> q;
        for(int i=0;i<n;i++){
            node N;
            cin >> N.h;
            N.id = i+1;
            q.push(N);
        }
        int flag = 0;
        while(k--){
            node N = q.top();
            q.pop();
            if(N.id==n){
                flag = 1;
                break;
            }
            if(k==0) N.h--;
            N.h++;
            q.push(N);
        }
        if(flag) cout << -1 << endl;
        else cout << q.top().id << endl;
    }

    return 0;
}