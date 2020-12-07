#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    ll n,m,k;
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        ll cnt = 1ll*(n/k)*(m/k);
        cout << cnt << endl;
    }

    return 0;
}