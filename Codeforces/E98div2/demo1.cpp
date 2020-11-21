#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e4+5;
int d[][2] = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};

struct Node
{
    int x = 0;
    int y = 0;
    int step = 0;
    int i = -1;
};

Node fin;
int vis[M][M];

void bfs(){
    queue<Node> q;
    Node frist;
    vis[0][0] = 1;
    q.push(frist);
    while(!q.empty()){
        Node new1 = q.front();
        q.pop();
        int mhd = abs(fin.x-new1.x) + abs(fin.y-new1.y);
        for(int i=0;i<5;i++){
            Node new2;
            new2.x = new1.x + d[i][0];
            new2.y = new1.y + d[i][1];
            new2.i = i;
            int mhd1 = abs(fin.x-new2.x) + abs(fin.y-new2.y);
            if(mhd1>mhd){
                continue;
            }
            if(new2.i!=new1.i&&new2.x>=0&&new2.x<fin.x+1&&new2.y>=0&&new2.y<fin.y+1){
                int flag = 0;
                if(!vis[new2.x][new2.y]&&!flag){
                    vis[new2.x][new2.y] = 1;
                    if(new2.x==fin.x&&new2.y==fin.y){
                        new2.step = new1.step + 1;
                        if(new2.step<fin.step){
                            fin.step = new2.step;
                        }
                        while(!q.empty()){
                            q.pop();
                        }
                        return;
                    }
                    new2.step = new1.step + 1;
                    cout << new2.x << new2.y << new2.step << '?';//debug
                    q.push(new2);
                    flag++;
                }
                if(new2.i==4&&!flag){
                    vis[new2.x][new2.y] = 1;    
                    if(new2.x==fin.x&&new2.y==fin.y){
                        new2.step = new1.step + 1;
                        if(new2.step<fin.step){
                            fin.step = new2.step;
                        }
                        while(!q.empty()){
                            q.pop();
                        }
                        return;
                    }
                    new2.step = new1.step + 1;
                    cout << new2.x << new2.y << new2.step << '?';//debug
                    q.push(new2);
                    flag++;
                }
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        fill(vis[0],vis[0]+M*M,0);
        cin >> fin.x >> fin.y;
        fin.step = INF;
        if(fin.x==0&&fin.y==0){
            cout << '0' << endl;
        }else{
            bfs();
            cout << fin.step << endl;
        }
    }
    return 0;
}