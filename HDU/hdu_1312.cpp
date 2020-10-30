#include <iostream>
#include <queue>
using namespace std;

int m[4][2]={
    {0,-1},
    {-1,0},
    {0,1},
    {1,0},
};
char s[20][20];

struct node{int x; int y;};

bool check(int x, int y,int w,int h){
    if(x>=0&&x<h&&y>=0&&y<w)return true;
    else return false;
}
int bfs(int x, int y,int w, int h){
    queue<node> k;
    node p;
    int sum = 1;
    p.x=x;
    p.y=y;
    k.push(p);
    int bx,by;
    while(!k.empty()){
        for(int i=0;i<4;i++){
            bx=k.front().x+m[i][0];
            by=k.front().y+m[i][1];
            // cout << bx<<by<<endl;
            if(check(bx,by,w,h)&&s[bx][by]=='.'){
                sum ++;
                p.x=bx;
                p.y=by;
                k.push(p);
                s[bx][by]='#';
            }
        }
        k.pop();
    }
    return sum;
}

int main(){
    int w,h;
    int x,y;
    while(scanf("%d%d",&w,&h)&&w!=0&&h!=0){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> s[i][j];
                if(s[i][j]=='@'){
                    x=i;y=j;
                }
            }
        }
        // cout <<x << y<<endl;
        cout << bfs(x,y,w,h) << endl;
    }

    return 0;
}