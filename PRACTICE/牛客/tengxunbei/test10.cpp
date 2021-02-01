#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(a%2){
            cout << 1ll*(a*1ll*(a+1)) << endl;
        }else{
            cout << -1*1ll*a*(1ll*(a+1)) << endl;
        }
    }

    return 0;
}