#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bool Judge(ll p){
    for(ll i=1;i*i+i*(i+1)+(i+1)*(i+1)<=p;i++){
        if(i*i+i*(i+1)+(i+1)*(i+1)==p){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    ll p;
    while(t--){
        cin >> p;
        if(Judge(p)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}