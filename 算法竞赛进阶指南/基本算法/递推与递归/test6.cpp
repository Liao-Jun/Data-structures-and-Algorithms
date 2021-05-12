//约数之和
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int mod = 9901;

ll mpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res%mod;
}

ll sum(ll p, ll k) {
    ll res = 1;
    if (k == 0) return 1;
    if (k%2 == 0) {
        return (p%mod*sum(p, k - 1) + 1)%mod;
    }else {
        return ((1 + mpow(p, k/2 + 1))*sum(p, k/2))%mod;
    }
}

ll a, b;

int main() {
    cin >> a >> b;
    ll res = 1;
    for (int i = 2; i <= a; i ++ ) {
        int s = 0;
        while (a%i == 0) {
            s ++;
            a /= i;
        }
        if(s) res = res*sum(i, s*b)%mod;
    }
    if (!a) res = 0;
    cout << res << endl;

    return 0;
}