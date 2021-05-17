//超快速排序
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int maxn = 5e5+10;

int n;
ll s[maxn], b[maxn];
ll cnt = 0;

void merge(int l, int r) {
    if (r <= l) return;
    int mid = (l + r) >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k ++ ) {
        if (j > r || i <= mid && s[i] <= s[j]) {
            b[k] = s[i ++];
        }else {
            b[k] = s[j ++];
            cnt += 1ll*(mid - i + 1);
        }
    }
    for (int k = l; k <= r; k ++ ) {
        s[k] = b[k];
    }
}

int main() {
    while (cin >> n && n) {
        cnt = 0;
        for (int i = 0; i < n; i ++ ) cin >> s[i];
        merge(0, n - 1);
        cout << cnt << endl;
    }

    return 0;
}