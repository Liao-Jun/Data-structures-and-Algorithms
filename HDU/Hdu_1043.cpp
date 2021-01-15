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
const int M = 362885;
string s;
int a,b;
int used[M];
struct node{
    int hash,flag;
    string s;
    node(string _s, int _hash, int _flag){
        s = _s;
        hash = _hash;
        flag = _flag;
    }
};
string pre[M];
const int dic[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const char dic_char[] = {'l','r','u','d'};
const int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};
int cantor(string s){
    int x = 0;
    for(int i=0;i<9;i++){
        int res = 0;
        for(int j=i+1;j<9;j++){
            if(s[i]>s[j]) res++;
        }
        x += res*fac[8-i];
    }
    return x;
}

void bfs(){
    queue<node> q;
    q.push(node("123456780",46233,8));
    used[46233] = 1;
    while(!q.empty()){
        node N = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = N.flag/3+dic[i][0];
            int y = N.flag%3+dic[i][1];
            if(x>=0&&x<3&&y>=0&y<3){
                int flag = 3*x+y;
                string st = N.s;
                swap(st[flag],st[N.flag]);
                int can = cantor(st);
                if(used[can]==0){
                    q.push(node(st,can,flag));
                    used[can] = 1;
                    pre[can] = pre[N.hash]+dic_char[i];
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
    memset(used,0,sizeof(used));
    bfs();
    while(cin >> c){
        s.clear();
        s.append(c);
        for(int i=0;i<8;i++){
            cin >> c;
            s.append(c);
        }
        for(int i=0;i<9;i++){
            if(s[i]=='x'){
                s[i] = '0';
                a = i/3;
                b = i%3;
            }
        }
        int can = cantor(s);
        if(used[can]==0){
            cout << "unsolvable" << endl;
        }else{
            string st = pre[can];
            reverse(st.begin(), st.end());
            cout << st << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/HDU-1043