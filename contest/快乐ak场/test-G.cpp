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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    string n;
    getline(cin,n,'\n');
    int sum = 0;
    int t = n[0]-'0';
    for(int k=0;k<t;k++){
        string s;
        getline(cin, s,'\n');
        for(auto it=s.begin();it!=s.end();++it){
            if(*it==' '){
                s.erase(it);
            }
        }
        cout << s.length() << endl;
        int flag = 0;
        for(int i=0;i<s.length();i++){
            if(i+3>=s.length()) break;
            if(s[i]=='A'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='n'){
                flag = 1;
                break;
            }
        }
        if(flag){
            for(int i=0;i<s.length();i++){
                if(s[i]=='%'){
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}