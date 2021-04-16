#include <iostream>

using namespace std;

const int maxn = 1e5+10;

using ll = long long;

int a[maxn];

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 2; i <= n; i++ ) {
        if (a[i] > a[i - 1]) {
            sum += 1ll*(a[i] - a[i - 1]);
        }
    }
    cout << sum << endl;

    return 0;
}