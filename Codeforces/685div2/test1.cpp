#include <iostream>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int cnt = 0;
        if(n==2){
            cnt = 1;
        }else if(n==3){
            cnt = 2;
        }else if(n==1){
            cnt = 0;
        }else if(n>3){
            if(n%2==0){
                cnt = 2;
            }else if(n%2==1){
                cnt = 3;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}