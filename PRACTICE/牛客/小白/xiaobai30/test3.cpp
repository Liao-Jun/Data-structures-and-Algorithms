#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll x = 4;
    ll y = 2;
    if(n%x==0){
        cout << y*(n/x) << endl;
    }else if(n%x==1){
        cout << y*(n/x)+1 << endl;
    }else if(n%x==2){
        cout << y*(n/x)+2 << endl;
    }else if(n%x==3){
        cout << y*(n/x)+1 << endl;
    }

    return 0;
}