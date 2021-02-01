#include <iostream>
using namespace std;

bool Judge(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int cnt = 1;
    for(int i=2;i<=n;i++){
        if(Judge(i)){
            cnt++;
        }
    }
    if(cnt==n){
        cout << -1 << endl;
    }else cout << cnt+1 << endl;

    return 0;
}