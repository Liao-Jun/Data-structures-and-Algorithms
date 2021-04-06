#include <iostream>

using namespace std;

using ll = long long;

const int M =1e5+10;

int a[M];
int tmp[M];
ll cnt;

void m_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    m_sort(l, mid);
    m_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else cnt += 1ll*(mid - i + 1), tmp[k ++] = a[j ++];
    }
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];
    for (i = l, j = 0; i <= r, j < k; i ++, j ++) {
        a[i] = tmp[j];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    cnt = 0;
    m_sort(0, n - 1);
    cout << cnt << endl;

    return 0;
}