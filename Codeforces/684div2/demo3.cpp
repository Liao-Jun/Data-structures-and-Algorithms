#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int M = 200+5;
int t,n,m;
int a[M][M];
int v[10000+5][6];
int cnt,mcnt;
string s;
int d[][4] = {{-1,0,-1,-1},{-1,0,-1,1},{0,-1,1,-1},{0,-1,-1,-1},{1,0,1,-1},{0,1,-1,1},{0,1,1,1},{1,0,1,1}};

int Sum(){
    int sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum += a[i][j];
        }
    }
    return sum;
}

void dfs(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                for(int i=0;i<8;i++){
                    if(a[i+d[i][0]][j+d[i][1]]==1&&a[i+d[i][2]][j+d[i][3]]==1){
                        a[i][j] = 0;
                        a[i+d[i][0]][j+d[i][1]] = 0;
                        a[i+d[i][2]][j+d[i][3]] = 0;
                        v[cnt][0] = i;
                        v[cnt][1] = j;
                        v[cnt][2] = i+d[i][0];
                        v[cnt][3] = j+d[i][1];
                        v[cnt][4] = i+d[i][2];
                        v[cnt][5] = j+d[i][3];
                        // cout << '?' << Sum() << '?';//debug
                        if(Sum()==0){
                            for(int k=0;k<cnt;k++){
                                for(int z=0;z<6;z++){
                                    cout << v[k][z] << ' ';
                                }
                                cout << endl;
                            }
                        }
                        cnt++;
                        if(cnt<=mcnt+1) dfs();
                        cnt--;
                        a[i][j] = 1;
                        a[i+d[i][0]][j+d[i][1]] = 1;
                        a[i+d[i][2]][j+d[i][3]] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        fill(v[0],v[0]+10005*6,0);
        for(int i=1;i<=n;i++){
            cin >> s;
            for(int j=1;j<=m;j++){
                a[i][j] = s[j-1]-'0';
            }
        }
        mcnt = 3*n*m;
        cnt = 0;
        dfs();
        cout << '?' << endl;
    }

    return 0;
}