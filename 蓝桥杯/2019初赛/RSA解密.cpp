#include <iostream>

using namespace std;

using ll = long long;

ll mpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res*(a%mod)%mod;
        b >>= 1;
        a = a*a%mod;
        cout << res << endl;
    }
    return res%mod;
}
ll n = 1001733993063167141;
ll d = 212353;
ll c = 20190324;

int main() {
    ll p, q;
    // // for (int i = 2; i*i < n; i ++ ) {
    // //     if (n%i == 0) {
    // //         p = i, q = n/p;
    // //         break;
    // //     }
    // // }
    // p = 891234941;
    // q = 1123984201;
    // ll m = n - p - q + 1;
    // ll e;
    // // for (int i = 0; ; i ++ ) {
    // //     ll x = m*i + 1;
    // //     if (x%d == 0) {
    // //         e = x/d;
    // //         break;
    // //     }
    // // }
    // e = 823816093931522017;
    // // cout << e;
    // cout << mpow(c, e, n);
    // // cout << 345175198675457258 << endl;
    cout << 579706994112328949 << endl;
    
    return 0;
}