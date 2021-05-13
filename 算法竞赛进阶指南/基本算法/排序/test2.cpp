//货仓选址
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int maxn = 1e5+10;

int n;
int a[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    sort(a, a + n);
    int x = a[n >> 1];
    ll sum = 0;
    for (int i = 0; i < n; i ++ ) {
        sum += 1ll*abs(x - a[i]);
    }
    cout << sum << endl;

    return 0;
}