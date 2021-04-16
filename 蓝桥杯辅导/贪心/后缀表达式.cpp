#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int maxn = 2e5+10;

int n, m;
ll a[maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m + 1; i ++ ) {
        cin >> a[i];
    }
    sort(a, a + n + m + 1);
    ll sum = 0;
    if (m == 0) {
        for (int i = 0; i < n + m + 1; i ++ ) {
            sum += a[i];
        }
    }else {
        sum = a[n + m] - a[0];
        for (int i = 1; i < n + m; i ++ ) {
            sum += abs(a[i]);
        }
    }
    cout << sum << endl;

    return 0;
}