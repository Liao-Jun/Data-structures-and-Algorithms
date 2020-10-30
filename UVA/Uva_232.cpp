#include <iostream>
#include <string>
using namespace std;

string s[11];
int x[11][11];
int y[11][11];

int main(){
    int r, c;
    int flag = 0;
    while(cin >> r&&r!=0){
        cin >> c;
        int sum = 1;
        for(int i=0;i<r;i++){
            cin >> s[i];
            for(int j=0;j<c;j++){
                if(s[i][j]=='*'){
                    x[i][j] = 0;
                    continue;
                }
                if(i==0||j==0){
                    x[i][j] = sum++;
                }else if(s[i-1][j]=='*'||s[i][j-1]=='*'){
                    x[i][j] = sum++;
                }else{
                    x[i][j] = 0;
                }
                y[i][j] = 0;
            }
        }
        if(flag!=0){
            cout << endl;
        }
        flag++;
        cout << "puzzle #" << flag << ':' << endl;
        cout << "Across" << endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(x[i][j]&&y[i][j]==0){
                    printf("%3d",x[i][j]);
                    cout << '.' << s[i][j];
                    y[i][j] = 1;
                    if(j==c-1)cout << endl;
                    for(int k=j+1;k<c;k++){
                        if(s[i][k]=='*'){
                            cout << endl;
                            break;
                        }
                        cout << s[i][k];
                        y[i][k] = 1;
                        if(k==c-1){
                            cout << endl;
                        }
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                y[i][j] = 0;
            }
        }
        cout << "Down" << endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(x[i][j]&&y[i][j]==0){
                    printf("%3d",x[i][j]);
                    cout << '.' << s[i][j];
                    y[i][j] = 1;
                    if(i==r-1)cout << endl;
                    for(int k=i+1;k<r;k++){
                        if(s[k][j]=='*'){
                            cout << endl;
                            break;
                        }
                        cout << s[k][j];
                        y[k][j] = 1;
                        if(k==r-1){
                            cout << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-232#author=0