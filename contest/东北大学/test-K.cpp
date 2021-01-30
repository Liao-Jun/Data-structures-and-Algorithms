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
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
string dic = "abcdefghijklmnopqrstuvwxyzBCDEFGHIJKLMNOPQRSTUVWXYZbcdefghijklmn";

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
    char a[4][4];
    int b[4][4];
    int c1 = 0, c2 = 0, r1 = 0, r2 = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[c2][r2] = s[i]-'0';
            r2++;
            if(c2==4){
                r2 = 0;
                c2++;
            }
        }else{
            a[c1][r1] = s[i];
            r1++;
            if(r1==4){
                r1 = 0;
                c1++;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]=='A'){
                a[i][j] += b[i][j];
                continue;
            }
            for(int k=0;k<66;k++){
                if(a[i][j]==dic[k]){
                    a[i][j] = dic[k+b[i][j]];
                    break;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            cout << a[i][j];
        }
    }
    cout << endl;

    return 0;
}