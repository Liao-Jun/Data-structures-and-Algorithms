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
string S = "12345678x";
string s;
map<string,int> dic;
vector<char> v;
map<string,pair<string,char>> pre;
struct node{
    string s;
    int x,y;
    node(string _s, int _x, int _y){
        s = _s;
        x = _x;
        y = _y;
    }
};
int d[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char dc[] = {'r','l','d','u'};
int bfs(){
    queue<node> q;
    int t = 0;
    for(int i=0;i<9;i++){
        if(s[i]=='x'){
            t = i;
            break;
        }
    }
    q.push(node(s,t/3,t%3));
    dic[s] = 1;
    while(!q.empty()){
        node N = q.front();
        q.pop();
        string st = N.s;
        if(st==S){
            while(st!=S){
                v.push_back(pre[st].second);
                st = pre[st].first;
            }
            return INF;
        }
        cout << '#' << N.x << ' ' << N.y << endl;//debug
        for(int i=0;i<4;i++){
            string sc = st;
            int x = N.x+d[i][0];
            int y = N.y+d[i][1];
            if(x>=0&&x<=2&&y>=0&&y<=2){
                cout << '@' << x << ' ' << y << endl;//debug
                swap(sc[N.x*3+N.y],sc[x*3+y]);
                cout << sc << endl;//debug
                if(dic[sc]==0){
                    q.push(node(sc,x,y));
                    dic[sc] = 1;
                    pre[sc].first = st;
                    pre[sc].second = dc[i];
                }
            }
        }
    }
    return 0;
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
    string c;
    while(cin >> c){
        s.clear();
        s.append(c);
        for(int i=0;i<8;i++){
            cin >> c;
            s.append(c);
        }
        cout << s << endl;//debug
        v.clear();
        pre.clear();
        dic.clear();
        int cnt = bfs();
        cout << '&' << cnt << endl;//debug
        if(cnt==INF){
            while(v.size()){
                cout << v.back();
                v.pop_back();
            }
            cout << endl;
        }else if(cnt==0){
            cout << "unsolvable" << endl;
        }
        break;//debug
    }

    return 0;
}