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
    int t,n,a;
    char s[50];
    cin >> t;
    while(t--){
        cin >> n;
        int cnt = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            while(res<a){
                s[cnt++] = '(';
                cout << '(';//debug
                res++;
            }
            s[cnt++] = ')';
            cout << ')';//debug
        }
        cout << endl;//debug
        vector<int> v;
        for(int i=0;i<cnt;i++){
            if(s[i]==')'){
                int sum = 1;
                cout << i << endl;//debug
                for(int j=i-1;j>=0;--j){
                    if(s[j]==')'){
                        sum++;
                    }else if(s[j]=='('){
                        v.push_back(sum);
                        s[j] = '#';
                    }
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1){
                cout << v[i] << endl;
                break;
            }
            cout << v[i] << ' ';
        }
    }

    return 0;
}