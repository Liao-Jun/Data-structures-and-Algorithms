#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    ll d[70];
    d[0] = 0;
    d[1] = 1;
    for(int i=2;i<70;i++){
        d[i] = d[i-1]+d[i-2];
    }
    while(t--){
        ll n;
        cin >> n;
        ll c = 1;
        int i;
        for(i=0;c<=n;i++){
            c*=2;
        }
        cout << d[i] << endl;
    }

    return 0;
}