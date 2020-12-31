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
float solve_h(float t,float d){
    float e = 6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
    float h = (0.5555)*(e-10.0);
    float h1 = h+t;
    return h1;
}

float solve_t(float d, float h1){
    float e = 6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
    float h = (0.5555)*(e-10.0);
    float t = h1-h;
    return t;
}

float solve_d(float t, float h1){
    float h = h1-t;
    float e = (h/0.5555)+10.0;
    float d = 1.0/(1.0/273.16-((log(e/6.11))/5417.7530))-273.16;
    return d;
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
    char a;
    map<char, float> dic;
    while(cin >> a&&a!='E'){
        dic.clear();
        int sum = 0;
        cin >> dic[a];
        sum += a;
        cin >> a >> dic[a];
        sum += a;
        if(sum=='T'+'D'){
            dic['H'] = solve_h(dic['T'],dic['D']);
        }else if(sum=='D'+'H'){
            dic['T'] = solve_t(dic['D'],dic['H']);
        }else if(sum=='T'+'H'){
            dic['D'] = solve_d(dic['T'],dic['H']);
        }
        printf("T %.1f D %.1f H %.1f\n",dic['T'],dic['D'],dic['H']);
    }

    return 0;
}