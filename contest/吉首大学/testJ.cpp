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

bool is_prime(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
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
    int cnt = 0;
    int a[100];
    for(int i=10;i<100;i++){
        if(is_prime(i)){
            int I = i;
            if(is_prime(I%10)){
                I = I/10;
                if(is_prime(I)){
                    I = I+i%10;
                    if(is_prime(I)){
                        a[cnt++] = i;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    cout << a[0];
    for(int i=1;i<cnt;i++){
        cout << ' ' << a[i];
    }
    cout << endl;

    return 0;
}