#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int t, n, d, x, y;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int main() {
    cin >> t;
    while (t --) {
        cin >> n >> d >> x >> y;
        ll p, q;
        ll gcd = exgcd(n, d, q, p);
        if ((y - x) % gcd) cout << "Impossible" << endl;
        else {
            p *= (y - x)/gcd;
            n /= gcd;
            cout << (p%n + n)%n << endl;
        }
    }

    return 0;
}