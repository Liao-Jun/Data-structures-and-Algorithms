#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
const int maxn = 1e5+10;

int n;
ll a[maxn];

int d(int x) {
    int t = 0;
    while (x >= 2) {
        t ++;
        x /= 2;
    }
    return t + 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    ll M = a[1];
    int T = 1;
    ll m = 0;
    int t = 0;
    for (int i = 2; i <= n; i ++ ) {
        if (d(i) != d(i - 1)) {
            if (m > M) {
                M = m;
                T = d(i - 1);
            }
            m = 0;
            m += a[i];
            t = d(i);
        }else {
            m += a[i];
        }
    }
    if (m > M) {
        M = m;
        T = d(a[n]);
    }
    cout << T << endl;

    return 0;
}