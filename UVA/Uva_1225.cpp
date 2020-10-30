#include <iostream>
using namespace std;

int t;
int n;
int y[11];

void Judge(int x){
    while(x>=10){
        int n = x%10;
        y[n] ++;
        x = x/10;
    }
    y[x] ++;
}

int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        for(int i=0;i<10;i++){
            y[i] = 0;
        }
        int sum = 0;
        cin >> n;
        for(int j=1;j<=n;j++){
            Judge(j);
        }
        for(int j=0;j<10;j++){
            if(j==9){
                cout << y[j] << endl;
                break;
            }
            cout << y[j] << ' ';
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1225