#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int a, b, c, k;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        b = 0;
        return a;
    }
    ll d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main() {
    while (cin >> a >> b >> c >> k && !(a == 0 && b == 0 && c == 0 && k == 0)) {
        ll x, y;
        ll z = (1ll<<k);
        ll d = exgcd(c, z, x, y);
        if ((b - a)%d) cout << "FOREVER" << endl;
        else {
            x *= (b - a)/d;
            y *= (b - a)/d;
            z /= d;
            cout << (x%z + z)%z << endl;
        }
    }

    return 0;
}