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
char dic[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    string s,s1;
    cin >> s;
    int flag = 0;
    for(int i=1;i<=s.length();i++){
        if(s[i-1]>='c'&&s[i-1]<='i'){
            s1.append(1,s[i-1]);
        }else if(s[i-1]=='j'||s[i-1]=='t'){
            flag = 0;
            break;
        }else if((s[i-1]>='k'&&s[i-1]<='s')||(s[i-1]>='u'&&s[i-1]<='z')){
            flag = 1;
            int x = s[i-1]-'a'+1;
            int a = x/10;
            int b = x%10;
            s1.append(1,dic[a-1]);
            s1.append(1,dic[b-1]);
        }else if(s[i-1]=='a'&&(s[i]>='a'&&s[i]<='i')){
            flag = 1;
            int x = 10+s[i]-'a'+1;
            s1.append(1,dic[x-1]);
            i++;
        }else if(s[i-1]=='b'&&(s[i]>='a'&&s[i]<='f')){
            flag = 1;
            int x = 10+s[i]-'a'+1;
            s1.append(1,dic[x-1]);
            i++;
        }else if(s[i-1]=='a'||s[i-1]=='b'&&((s[i]>='k'&&s[i]<='s')||(s[i]>='u'&&s[i]<='z'))){
            flag = 1;
            s1.append(1,s[i-1]);
        }else if(s[i-1]=='a'&&(s[i]=='j'||s[i]=='t')){
            s1.append(1,s[i-1]);
        }else if(s[i-1]=='b'){
            s1.append(1,s[i-1]);
        }
        if(i==s.length()) break;
    }
    if(flag==0) cout << -1 << endl;
    else{
        if(s1.length()>2e6) cout << -1 << endl;
        else cout << s1 << endl;
    }

    return 0;
}