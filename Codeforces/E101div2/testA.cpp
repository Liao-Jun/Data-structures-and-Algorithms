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
    while(t--){
        string s;
        cin >> s;
        stack<char> q;
        while(!q.empty()){
            q.pop();
        }
        int flag = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') q.push('(');
            else if(s[i]==')'){
                if(q.empty()){
                    flag = 1;
                    break;
                }else{
                    q.pop();
                }
            }else if(s[i]=='?'){
                if(q.empty())q.push('(');
                else if(q.top()=='?') q.push('?');
                else if(q.top()=='(') q.push('?');
            }
        }
        while(!q.empty()){
            char x = q.top();
            q.pop();
            if(q.empty()){
                flag = 1;
            }
            if(x=='?'){
                q.pop();
            }else{
                flag = 1;
            }
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}