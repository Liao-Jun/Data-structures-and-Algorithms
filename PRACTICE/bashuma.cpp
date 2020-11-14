#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int M = 1E5;
const int MHASH = 1E5+5;
int head[MHASH],nt[M];
const int d[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
typedef int state[9];
state a[M],st = {1,2,3,8,0,4,7,6,5},goal;
int cnt = 1;

struct Node
{
    state a;
    int dis;
};

int Hush(state &a){
    int s = 0;
    for(int i=0;i<9;i++){
        s = s*10+a[i];
    }
    return s;
}

bool try_next(int x){
    int h = Hush(a[x]);
    int u = head[h];
    while(u){
        if(!memcmp(a[u],a[x],sizeof(a[u]))){
            return 0;
        }
        u = nt[u];
    }
    nt[x] = head[h];
    head[h] = x;
    return 1;
}

int bfs(){
    Node head;
    memcmp(head.a, st,sizeof(head.a));
    head.dis = 0;
    queue<Node> q;
    try_next(0);
    q.push(head);
    while(!q.empty()){
        head = q.front();
        q.pop();
        int z;
        for(z=0;z<9;z++){
            if(head.a[z]==0){
                break;
            }
        }
        int x = z%3;
        int y = z/3;
        for(int i=0;i<4;i++){
            int newx = x+d[i][0];
            int newy = y+d[i][1];
            int newz = newx = 3*newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){
                Node newnode;
                memcpy(newnode.a,head.a,sizeof(head.a));
                swap(newnode.a[z],newnode.a[newz]);
                newnode.dis = head.dis;
                newnode.dis ++;
                memcpy(a[cnt++],newnode.a,sizeof(a[0]));
                if(!memcmp(newnode.a,goal,sizeof(goal))){
                    return newnode.dis;
                }
                if(try_next(cnt-1)){
                    q.push(newnode);
                }
            }
        }
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        goal[i] = s[i]-'0';
    }
    memcpy(a[0],st,sizeof(a[0]));
    int x = bfs();
    if(x==0){
        cout << 0;
    }else{
        cout << x << endl;
    }

    return 0;
}