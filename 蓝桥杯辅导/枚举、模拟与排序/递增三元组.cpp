#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
const int M = 1e5+10;

int n;
int a[M], b[M], c[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];
    for (int i = 0; i < n; i ++ ) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    ll cnt = 0;
    for (int i = 0;i < n; i ++ ) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid] < b[i]) l = mid;
            else r = mid - 1;
        }
        if (a[l] >= b[i]) l = -1;
        ll sum = l + 1;
        l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (c[mid] > b[i]) r = mid;
            else l = mid + 1;
        }
        if (c[l] <= b[i]) r = n;
        sum *= 1ll*(n - r);
        cnt += 1ll*sum;
    }
    cout << cnt << endl;

    return 0;
}