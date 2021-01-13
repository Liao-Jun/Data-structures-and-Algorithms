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
int a,b;
string S = "12345678x";
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char dic1[] = {'r','l','d','u'};
map<string,int> used;
map<string,int> state;
map<string,pair<string,int>> pre,child;
struct node{
    string s;
    int x,y;
    node(string _s = "1", int _x = 0, int _y = 0){
        s = _s;
        x = _x;
        y = _y;
    }
};
vector<int> v;
void dbfs(){
    queue<node> q1;
    queue<node> q2;
    q1.push(node(s,a,b));
    q2.push(node(S,2,2));
    state[s] = 1;
    state[S] = 2;
    used[s] = 1;
    used[S] = 1;
    while(!(q1.empty())&&!(q2.empty())){
        int flag = 0;
        node N;
        if(q1.size()<q2.size()){
            N = q1.front();
            q1.pop();
        }else{
            N = q2.front();
            q2.pop();
            flag = 1;
        }
        for(int i=0;i<4;i++){
            string st = N.s;
            int x = N.x+dic[i][0];
            int y = N.y+dic[i][1];
            if(x>=0&&x<3&&y>=0&&y<3){
                swap(st[x*3+y],st[N.x*3+N.y]);
                if(!used.count(st)){
                    used[st] = 1;
                    state[st] = state[N.s];
                    if(flag==1){
                        q2.push(node(st,x,y));
                        pre[st].first = N.s;
                        pre[st].second = i;
                    }else{
                        q1.push(node(st,x,y));
                        child[st].first = N.s;
                        child[st].second = i;
                    }
                }else if(state[st]+state[N.s]==3){
                    string st = N.s;
                    while(st!=s){
                        v.push_back(pre[st].second);
                        st = pre[st].first;
                    }
                    cout << dic1[pre[s].second];
                    while(v.size()){
                        cout << dic1[v.back()];
                        v.pop_back();
                    }
                    st = child[N.s].first;
                    while(st!=S){
                        cout << dic1[child[st].second];
                        st = child[st].first;
                        cout << st << '&' << endl;//debug
                    }
                    return;
                }
            }
        }
    }
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
        for(int i=0;i<9;i++){
            if(s[i]=='x'){
                a = i/3;
                b = i%3;
            }
        }
        state.clear();
        pre.clear();
        child.clear();
        used.clear();
        v.clear();
        dbfs();
    }

    return 0;
}