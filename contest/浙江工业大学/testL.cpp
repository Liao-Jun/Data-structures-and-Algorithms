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
int is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return i;
    }
    return 1;
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
    int t;
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << 1 << endl;
            cout << 1 << endl;
        }else if(n%2==0){
            cout << (n/2+n/2-1) << endl;
            cout << 1;
            for(int i=1;i<n-1;i++){
                if(i%2==1) cout << ' ' << 1;
                else cout << ' ' << i+1;
            }
            cout << endl;
        }else if(n%2==1){
            if(is_prime(n)==1){
                cout << n-1 << endl;
                cout << n-1;
                for(int i=1;i<n-1;i++){
                    cout << ' ' << n-1-i;
                }
                cout << endl;
            }else{
                int x = is_prime(n);
                cout << n-1 << endl;
                cout << x-1;
                int cnt = 0;
                for(int i=1;i<n-1;i++){
                    if((i+1)%x==0) cout << ' ' << x;
                    else{
                        cout << ' ' << ((i+1)/x)*x+(x-(i+1)%x);
                    }
                }
            }

        }
    }

    return 0;
}