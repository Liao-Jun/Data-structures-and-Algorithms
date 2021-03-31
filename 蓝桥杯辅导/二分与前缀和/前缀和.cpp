#include <iostream>

using namespace std;

const int M = 1e5+10;
int n, m, l, r;
int a[M], sum[M];

int main() {
    cin >> n >> m;
    sum[0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        sum[i] = a[i] + sum[i-1];
    }
    while (m --) {
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << endl;
    }

    return 0;
}