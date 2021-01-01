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
struct node{
    string s;
    int a;
    int b;
    int sum;
};
node x[5];
string s1[5] = {{"qh"},{"sh"},{"hl"},{"xx"},{"kt"}};
bool cmp(const node &a,const node &b){
    return a.sum>=b.sum;
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
    for(int i=0;i<5;i++){
        x[i].s = s1[i];
    }
    string s;
    for(int i=0;i<5;i++){
        cin >> s;
        int a = 0;
        for(int i=0;i+6<s.length();i++){
            if(s[i]=='b'&&s[i+1]=='u'&&s[i+2]=='h'&&s[i+3]=='u'&&s[i+4]=='i'&&s[i+5]=='b'&&s[i+6]=='a'){
                a++;
            }
        }
        x[i].a = a;
        int b = 0;
        for(int i=0;i+5<s.length();i++){
            if(s[i]=='j'&&s[i+1]=='i'&&s[i+2]=='u'&&s[i+3]=='z'&&s[i+4]=='h'&&s[i+5]=='e'){
                b++;
            }
        }
        x[i].b = b;
        x[i].sum = x[i].a+x[i].b;
        cout << x[i].s << ' ' << x[i].a << ' ' << x[i].b << endl;
    }
    sort(x,x+5,cmp);
    if(x[0].sum==x[1].sum) cout << "yygqdss" << endl;
    else cout << x[0].s << endl;

    return 0;
}