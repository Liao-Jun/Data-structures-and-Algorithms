#include <iostream>
#include <string>
using namespace std;

string s[100];
int d[][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int cnt,n,m;

void dfs(int x, int y){
    s[x][y] = '.';
    for(int i=0;i<8;i++){
        int bx = x+d[i][0];
        int by = y+d[i][1];
        if(bx>=0&&bx<n&&by>=0&&by<m&&s[bx][by]=='W'){
            dfs(bx,by);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='W'){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-2386