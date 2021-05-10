//64位整数乘法
#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll a, b, p;

ll q_mul(ll a, ll b, ll p) {
    ll res = 0;
    while (b > 0) {
        if (b&1) res = (res + a)%p;
        a = (a*2)%p;
        b >>= 1;
    }
    return res%p;
}

int main() {
    cin >> a >> b >> p;
    cout << q_mul(a, b, p) << endl;

    return 0;
}