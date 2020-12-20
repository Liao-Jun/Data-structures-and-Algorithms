#include <iostream>
using namespace std;

typedef long long ll;
ll n;

bool judge(ll x){
    ll y = x;
    while(y>9){
        if(y%10){
            if(x%(y%10)!=0) return false;
        }
        y /= 10;
    }
    if(x%y!=0) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(ll i=n;;i++){
            if(judge(i)){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}