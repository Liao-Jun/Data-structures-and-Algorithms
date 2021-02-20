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
int dic[][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
bool check(int n){
    if(n%400==0) return true;
    if(n%100==0) return false;
    if(n%4==0) return true;
    return false;
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
    map<int,int> dic_num;
    int n;
    cin >> n;
    int num = 0;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(check(i+1900)) flag = 1;
        else flag = 0; 
        for(int j=0;j<12;j++){
            num += 13;
            dic_num[num%7] ++;
            num += (dic[j][flag]-13);
        }
    }
    cout << dic_num[6] << ' ';
    for(int i=0;i<=5;i++){
        cout << dic_num[i] << ' ';
    }

    return 0;
}