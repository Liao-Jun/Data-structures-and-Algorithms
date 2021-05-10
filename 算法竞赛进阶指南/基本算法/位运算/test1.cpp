//a^b
#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll a, b, p;

ll mpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b&1) res = (res*a)%p;
        a = a*a%p;
        b >>= 1;
    }
    return res%p;
}

int main() {
    cin >> a >> b >> p;
    cout << mpow(a, b, p) << endl;

    return 0;
}