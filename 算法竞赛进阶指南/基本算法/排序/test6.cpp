//奇数码问题
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int maxn = 500*500 + 10;

int n, x;
int a[maxn], b[maxn], c[maxn];
ll cnt;

void merge(int x[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge(x, l, mid);
    merge(x, mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k ++ ) {
        if (j > r || i <= mid && x[i] <= x[j]) {
            c[k] = x[i ++];
        }else {
            c[k] = x[j ++];
            cnt += 1ll*(mid - i + 1);
        }
    }
    for (int k = l; k <= r; k ++ ) {
        x[k] = c[k];
    }
}

int main() {
    while (cin >> n) {
        int flag = 0;
        for (int i = 0; i < n*n; i ++ ) {
            cin >> x;
            if (x == 0) flag = 1;
            else a[i - flag] = x;
        }
        flag = 0;
        for (int i = 0; i < n*n; i ++ ) {
            cin >> x;
            if (x == 0) flag = 1;
            else b[i - flag] = x;
        }
        cnt = 0;
        memset(c, 0, sizeof(c));
        merge(a, 0, n*n - 2);
        ll res = cnt;
        cnt = 0;
        memset(c, 0, sizeof(c));
        merge(b, 0, n*n - 2);
        if ((cnt&1) == (res&1)) {
            cout << "TAK" << endl;
        }else cout << "NIE" << endl;
    }

    return 0;
}