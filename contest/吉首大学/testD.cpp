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
const int M = 2e6+10;

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
    char a[20]; 
    map<char,int> dic = {{'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'J',10},{'Q',11},{'K',12}};
    int flag = 1;
    int sum1 = 0;
    int sum2 = 0;
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        if(flag == 1){
            a[cnt++] = s[i];
            for(int j=cnt-2;j>=0;j--){
                if(s[i]==a[j]){
                    int sum = 0;
                    for(int k=j;k<cnt;k++){
                        sum += dic[a[k]];
                    }
                    sum1 += sum;
                    cnt = j;
                    flag = -1;
                    break;
                }
            }
            flag = -1;
        }else{
            a[cnt++] = s[i];
            for(int j=cnt-2;j>=0;j--){
                if(s[i]==a[j]){
                    int sum = 0;
                    for(int k=j;k<cnt;k++){
                        sum += dic[a[k]];
                    }
                    sum2 += sum;
                    cnt = j;
                    flag = 1;
                    break;
                }
            }
            flag = 1;
        }
    }
    if(sum2==sum1) cout << -1 << endl;
    else{
        if(sum1>sum2){
            cout << "zqc " << sum1 << endl;
        }else{
            cout << "lbg " << sum2 << endl;
        }
    }

    return 0;
}