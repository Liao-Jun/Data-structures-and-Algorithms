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
string s;
int cnt = 0;
int check(int i){
    char c = s[cnt++];
    if(c=='p'||c=='q'||c=='s'||c=='t') return (i>>(c-'p'))&1;
    else if(c=='K') return check(i)&check(i);
    else if(c=='A') return check(i)|check(i);
    else if(c=='N') return !check(i);
    else if(c=='C') return (!check(i))|check(i);
    else if(c=='E') return check(i)==check(i);
    else return 0;
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
    int flag;
    while(cin >> s&&s[0]!='0'){
        flag = 1;
        for(int i=0;i<32;i++){
            cnt = 0;
            if(!check(i)){
                flag = -1;
                break;
            }
        }
        if(flag==1) cout << "tautology" << endl;
        else cout << "not" << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3295