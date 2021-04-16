#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int maxn = 1e5+10;

int a[maxn];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    int x = a[n >> 1];
    ll sum = 0;
    for (int i = 0; i < n; i ++ ) {
        sum += 1ll*abs(a[i] - x);
    }
    cout << sum << endl;

    return 0;
}