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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    string s;
    cin >> s;
    int cnt = 1;
    int sum = 0;
    int flag = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'||s[i]=='X'){
            if(cnt==10){
                sum %= 11;
                if(s[i]=='X'){
                    if(sum==10) flag = 1;
                    else s[i] = sum+'0';
                }else{
                    if(sum==s[i]-'0') flag = 1;
                    else{
                        if(sum==10) s[i] = 'X';
                        else s[i] = sum+'0';
                    }
                }
            }
            sum += (s[i]-'0')*cnt;
            cnt++;
        }
    }
    if(flag) cout << "Right" << endl;
    else cout << s << endl;

    return 0;
}