#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

ll qpow(ll x, ll y)
{
   ll res = 1;
   while(y){
      if(y & 1) res = res * x % mod;
      x = x * x % mod;
      y>>=1;
   }
   return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ll p,q = 1;
        q = qpow(n,m);

        p = q-1;

        cout << p*qpow(q,mod-2)%mod << endl;
    }

    return 0;
}