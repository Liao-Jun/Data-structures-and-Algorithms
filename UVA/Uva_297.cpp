#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1024+5;
int d[maxn][maxn];
int cnt;

void draw(string s, int &f,int r,int c, int w){
    if(f>=s.size()) return;
    char m = s[f++];
    if(m=='p'){
        draw(s,f,r,c+w/2,w/2);
        draw(s,f,r,c,w/2);
        draw(s,f,r+w/2,c,w/2);
        draw(s,f,r+w/2,c+w/2,w/2);
    }else if(m=='f'){
        for(int i=r;i<r+w;i++){
            for(int j=c;j<c+w;j++){
                if(d[i][j]==0){
                    d[i][j]=1;
                    cnt++;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        memset(d, 0, sizeof(d));
        cnt = 0;
        int f = 0;
        draw(s1,f,0,0,32);
        f = 0;
        draw(s2,f,0,0,32);
        printf("There are %d black pixels.\n", cnt);
    }

    return 0;
}

//https://vjudge.net/problem/UVA-297