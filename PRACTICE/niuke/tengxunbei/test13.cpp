#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a = k%(1ll*2*n);
    if(a==0){
        cout << s[0] << endl;
    }else if(a>n){
        cout << s[n-a+n] << endl;
    }else{
        cout << s[a-1] << endl;
    }

    return 0;
}