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
    int cnt = 0;
    while(t--){
        int len;
        cin >> len;
        string s1,s2,s;
        cin >> s1 >> s2 >> s;
        int res = 0;
        string s3;
        cout << ++cnt << ' ';
        while(1){
            res++;
            for(int i=0;i<2*len;i++){
                if(i%2==0){
                    s3 += s2[i/2];
                }else{
                    s3 += s1[i/2];
                }
            }
            if(s==s3){
                cout << res << endl;
                break;
            }
            else{
                s1 = s3.substr(0,len);
                s2 = s3.substr(len,len);
                s3.clear();
            }
            if(res>100){
                cout << -1 << endl;
                break;
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3087