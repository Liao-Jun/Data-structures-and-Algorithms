#include <iostream>
#include <string>
using namespace std;

string s[100+5];
int m,n,cnt;

int d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

void dfs(int x, int y){
    if(x<0||x>=m||y<0||y>=n) return;
    if(s[x][y]=='*')return;
    s[x][y] = '*';
    for(int i=0;i<8;i++){
        int x1 = x+d[i][0];
        int y1 = y+d[i][1];
        if(x1>=0&&x1<m&&y1>=0&&y1<n&&s[x1][y1]=='@') dfs(x1, y1);
    }

}

int main(){
    while(scanf("%d%d",&m,&n)==2&&m!=0){
        cnt = 0;
        getchar();
        for(int i=0;i<105;i++) s[i].clear();
        for(int i=0;i<m;i++){
            getline(cin, s[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='@'){
                    cnt++;
                    dfs(i, j);
                }

            }
        }
        cout << cnt <<endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-572
