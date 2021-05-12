//分形之城
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int t, n;
ll a, b;

pll calc(ll n, ll m) {
    if (n == 0) return make_pair(0, 0);
    ll len = 1ll << (n - 1);
    ll cnt = 1ll << (2*n - 2);
    pll p = calc(n - 1, m%cnt);
    ll x = p.first, y = p.second;
    int z = m/cnt;
    if (z == 0) return make_pair(y, x);
    if (z == 1) return make_pair(x, y + len);
    if (z == 2) return make_pair(x + len, y + len);
    return make_pair(2*len - 1 - y, len - 1 - x);
}

int main() {
    cin >> t;
    while (t -- ) {
        cin >> n >> a >> b;
        pll pa = calc(n, a - 1);
        pll pb = calc(n, b - 1);
        ll dx = pa.first - pb.first, dy = pa.second - pb.second;
        double res = (sqrt(dx*dx + dy*dy)*10);
        printf("%.0lf\n", res);
    }

    return 0;
}