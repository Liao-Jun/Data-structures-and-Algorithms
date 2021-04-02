#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e5+10;

int a[M], b[M];

void m_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    m_sort(l, mid);
    m_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k ++] = a[i ++];
        else b[k ++] = a[j ++];
    }
    while (i <= mid) b[k ++] = a[i ++];
    while (j <= r) b[k ++] = a[j ++];
    for (i = l, j = 0; i <= r, j < k; i ++, j ++ ) {
        a[i] = b[j];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    m_sort(0, n - 1);
    for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';

    return 0;
}