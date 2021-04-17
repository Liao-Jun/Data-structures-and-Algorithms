#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int n;
ll x[105], a[105], b[105];

ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}

ll gcd_sub(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 1) return x;
    return gcd_sub(y, x/y);
}

int main() {
    cin >> n;
    for (int i = 0;i < n; i ++ ) cin >> x[i];
    sort(x, x + n);
    int cnt = 0;
    for (int i = 1; i < n; i ++ ) {
        if (x[i] != x[i - 1]) {
            ll g = gcd(x[i], x[0]);
            a[cnt] = x[i]/g;
            b[cnt] = x[0]/g;
            cnt ++;
        }
    }
    ll A = a[0], B = b[0];
    for (int i = 1; i < cnt; i ++ ) {
        A = gcd_sub(A, a[i]);
        B = gcd_sub(B, b[i]);
    }
    cout << A << '/' << B << endl;

    return 0;
}