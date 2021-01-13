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
int s[5][5];
P pre[5][5];
P child[5][5];
int used1[5][5];
int used2[5][5];
int dic[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
vector<P> v;
void dbfs(){
    queue<P> q1;
    queue<P> q2;
    q1.push(make_pair(0,0));
    q2.push(make_pair(4,4));
    used1[0][0] = 1;
    used2[4][4] = 1;
    while(!q1.empty()&&!q2.empty()){
        if(q1.size()<=q2.size()){
            P p = q1.front();
            q1.pop();
            for(int i=0;i<4;i++){
                int x = p.first+dic[i][0];
                int y = p.second+dic[i][1];
                if(x>=0&&x<=4&&y>=0&&y<=4&&s[x][y]==0){
                    if(used1[x][y]==0){
                        q1.push(make_pair(x,y));
                        used1[x][y] = 1;
                        pre[x][y].first = p.first;
                        pre[x][y].second = p.second;
                    }else if(used1[x][y]+used2[x][y]==2){
                        int x11 = x;
                        int y11 = y;
                        while(!(x11==0&&y11==0)){
                            v.push_back(make_pair(x11,y11));
                            int x22 = x11;
                            int y22 = y11;
                            x11 = pre[x22][y22].first;
                            y11 = pre[x22][y22].second;
                        }
                        cout << "(0, 0)" << endl;
                        while(v.size()){
                            cout << '(' << v.back().first << ", " << v.back().second << ')' << endl;
                            v.pop_back();
                        }
                        while(!(x==4&&y==4)){
                            cout << '(' << child[x][y].first << ", " << child[x][y].second << ')' << endl;
                            int x11 = x;
                            int y11 = y;
                            x = child[x11][y11].first;
                            y = child[x11][y11].second;
                        }
                        return;
                    }
                }
            }
        }else{
            P p = q2.front();
            q2.pop();
            for(int i=0;i<4;i++){
                int x = p.first+dic[i][0];
                int y = p.second+dic[i][1];
                if(x>=0&&x<=4&&y>=0&&y<=4&&s[x][y]==0){
                    if(used2[x][y]==0){
                        q2.push(make_pair(x,y));
                        used2[x][y] = 1;
                        child[x][y].first = p.first;
                        child[x][y].second = p.second;
                    }else if(used1[x][y]+used2[x][y]==2){
                        int x11 = x;
                        int y11 = y;
                        while(!(x11==0&&y11==0)){
                            v.push_back(make_pair(x11,y11));
                            int x22 = x11;
                            int y22 = y11;
                            x11 = pre[x22][y22].first;
                            y11 = pre[x22][y22].second;
                        }
                        cout << "(0, 0)" << endl;
                        while(v.size()){
                            cout << '(' << v.back().first << ", " << v.back().second << ')' << endl;
                            v.pop_back();
                        }
                        while(!(x==4&&y==4)){
                            cout << '(' << child[x][y].first << ", " << child[x][y].second << ')' << endl;
                            int x11 = x;
                            int y11 = y;
                            x = child[x11][y11].first;
                            y = child[x11][y11].second;
                        }
                        return;
                    }
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
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> s[i][j];
        }
    }
    memset(used1,0,sizeof(used1));
    memset(used2,0,sizeof(used2));
    dbfs();

    return 0;
}

//https://vjudge.net/problem/POJ-3984