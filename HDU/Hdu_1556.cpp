#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 1e5+10;

int a[M], d[M];
int n;

int main() {
    while (cin >> n && n != 0) {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i ++ ) {
            int l, r;
            cin >> l >> r;
            d[l] += 1;
            d[r + 1] -= 1;
        }
        for (int i = 1; i <= n; i ++ ) {
            a[i] += a[i - 1] + d[i];
        }
        for (int i = 1; i < n; i ++ ) cout << a[i] << ' ';
        cout << a[n] << endl;
    }

    return 0;
}