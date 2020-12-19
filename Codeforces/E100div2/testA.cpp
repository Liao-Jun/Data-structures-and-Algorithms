#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    int a,b,c;
    while(t--){
        cin >> a >> b >> c;
        int x = a;
        x = min(x,b);
        x = min(x,c);
        int sum = a+b+c;
        if(sum%9==0&&sum/9<=x){
            cout << "YES\n";
        }else cout << "NO\n";
    }

    return 0;
}