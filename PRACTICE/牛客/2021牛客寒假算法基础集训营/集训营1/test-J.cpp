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
inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
const int M = 1.6e8+5;
int a[M];
ll sum = 1;
ll g = 0;
void Eratosthenes_prime(int x)//a[i]==0为素数
{
    memset(a,0,sizeof(a));
    for(int i=2;i<=x;i++)
    {
        if(!a[i])
        {
            for(int j=i*i;j<=x;j+=i) a[j]=1;
            for(int j=i*i;j<=x;j*=i) a[j]++;
        }else if(a[i]==1){
            sum *= (1ll*i)%Mod;
            if(g==0) g = i;
            else g = gcd(i,g);
        }
    }
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
    int n;
    cin >> n;
    Eratosthenes_prime(n);
    if(sum==1&&g==0){
        cout << "empty" << endl;
    }else if(sum==6&&g==6) cout << 6 << endl;
    else cout << (sum/g)%Mod << endl;

    return 0;
}