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
int m,n,p;
int f[100];
int fib(int x){
    if(x==1){
        return 1;
    }
    if(x==2){
        return 2;
    }
    return fib(x-1)+fib(x-2);
}

void table(){
    int i=1;
    int x = 0;
    while(x<=1000){
        f[i] = fib(i);
        i++;
        x = f[i-1];
    }
}

int judge(int x){
    int i = 15;
    int cnt = 0;
    while(x!=0){
        if(x>=f[i]){
            x -= f[i];
            cnt++;
        }else{
            i--;
        }
    }
    return cnt;
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
    table();
    while(cin >> m >> n >> p && !(m==0&&n==0&&p==0)){
        int sum = 0;
        sum = judge(m)+judge(n)+judge(p);
        if(sum%2==1) cout << "Fibo" << endl;
        else cout << "Nacci" << endl;
    }

    return 0;
}