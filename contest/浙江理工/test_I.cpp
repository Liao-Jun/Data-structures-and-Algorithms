#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = n/2+3;
    string s;
    for(int i=1;i<=x;i++){
        int flag = 0;
        for(int j=1;j<=n/2+2;j++){
            if(n/2+2-(i-2)==j||flag){
                s[j] = '*';
                cout << '*';
                if(i==x-1){
                    flag = 1;
                }
                continue;
            }
            s[j] = ' ';
            cout << ' ';
        }
        if(i==1||i==x-1){
            cout << '*';
        }else{
            cout << ' ';
        }
        for(int j=n/2+2;j>=1;j--){
            cout << s[j];
        }
        cout << ' ';
        if(i==1||i==x){
            cout << ' ';
            int t = n;
            while(t--){
                cout << '*';
            }
            cout << endl;
        }else{
            cout << '*';
            cout << endl;
        }
    }

    return 0;
}