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
struct node{
    int g,id,sex;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n;
    map<string,node> dic;
    set<string> se1[105];
    cin >> n;
    string s1;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin >> s1 >> a >> b >> c;
        dic[s1].g = a;
        dic[s1].sex = b;
        dic[s1].id = c;
        se1[a].insert(s1);
    }
    int m;
    cin >> m;
    int t;
    for(int i=0;i<m;i++){
        cin >> t;
        if(t==1){
            cin >> s1;
            cout << dic[s1].g << ' ' << dic[s1].id << ' ' << dic[s1].sex << endl;
        }else if(t==2){
            cin >> a;
            if(!se1[a].empty()){
                for(auto it:se1[a]){
                    cout << it << endl;
                }
            }
        }
    }

    return 0;
}