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
map<char,int> dic = {{'N',0},{'E',1},{'S',2},{'W',3}};
struct node{
    int x,y;
    int dir;
};
struct Node{
    int x,y,id;
    Node(int _x, int _y, int _id){
        x = _x;
        y = _y;
        id = _id;
    }
};
int a,b,n,m;
node N[105];
set<Node> se;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cin >> n >> m;
        char c;
        se.clear();
        for(int i=1;i<=n;i++){
            cin >> N[i].x >> N[i].y;
            cin >> c;
            se.insert(Node(N[i].x,N[i].y),i));
            N[i].dir = dic[c];
        }
        int id,f;
        int flag = 0;
        for(int i=0;i<m;i++){
            cin >> id >> c >> f;
            if(flag==1) continue;
            if(c=='L') N[id].dir = (N[id].dir-f)%4;
            else if(c=='R') N[id].dir = (N[id].dir+f)%4;
            else if(c=='F'){
                for(set<Node>::iterator it=se.begin();it!=se.end();++it){
                    if(it->x==N[id].x&&it->id==id&&it->y==N[id].y){
                        se.erase(it);
                        break;
                    }
                }
                if(N[id].dir==0){
                    for(int j=0;j<f;j++){
                        N[id].y++;
                        if(se.find(Node(N[id].x,N[id].y,id))!=se.end()){
                            flag = 1;
                            cout << "Robot " << id << " crashes into robot " << se.find(Node(N[id].x,N[id].y,id))->id << endl;
                            break;
                        }
                    }
                    if(flag==0){
                        if(N[id].x>=1&&N[id].x<=a&&N[id].y>=1&&N[id].y<=b){
                            continue;
                        }else{
                            cout << "Robot " << id << " crashes into the wall" << endl;
                        }
                    }
                    if(flag==0) se.insert(Node(N[id].x,N[id].y,id));
                }else if(N[id].dir==1){
                    for(int j=0;j<f;j++){
                        N[id].x++;
                        if(se.find(Node(N[id].x,N[id].y,id))!=se.end()){
                            flag = 1;
                            cout << "Robot " << id << " crashes into robot " << se.find(Node(N[id].x,N[id].y,id))->id << endl;
                            break;
                        }
                    }
                    if(flag==0){
                        if(N[id].x>=1&&N[id].x<=a&&N[id].y>=1&&N[id].y<=b){
                            continue;
                        }else{
                            cout << "Robot " << id << " crashes into the wall" << endl;
                        }
                    }
                    if(flag==0) se.insert(Node(N[id].x,N[id].y,id));
                }else if(N[id].dir==2){
                    for(int j=0;j<f;j++){
                        N[id].y--;
                        if(se.find(Node(N[id].x,N[id].y,id))!=se.end()){
                            flag = 1;
                            cout << "Robot " << id << " crashes into robot " << se.find(Node(N[id].x,N[id].y,id))->id << endl;
                            break;
                        }
                    }
                    if(flag==0){
                        if(N[id].x>=1&&N[id].x<=a&&N[id].y>=1&&N[id].y<=b){
                            continue;
                        }else{
                            cout << "Robot " << id << " crashes into the wall" << endl;
                        }
                    }
                    if(flag==0) se.insert(Node(N[id].x,N[id].y,id));
                }else if(N[id].dir==3){
                    for(int j=0;j<f;j++){
                        N[id].x--;
                        if(se.find(Node(N[id].x,N[id].y,id))!=se.end()){
                            flag = 1;
                            cout << "Robot " << id << " crashes into robot " << se.find(Node(N[id].x,N[id].y,id))->id << endl;
                            break;
                        }
                    }
                    if(flag==0){
                        if(N[id].x>=1&&N[id].x<=a&&N[id].y>=1&&N[id].y<=b){
                            continue;
                        }else{
                            cout << "Robot " << id << " crashes into the wall" << endl;
                        }
                    }
                    if(flag==0) se.insert(Node(N[id].x,N[id].y,id));
                }
            }
        }
        if(flag==0){
            cout << "OK" << endl;
        }
    }

    return 0;
}