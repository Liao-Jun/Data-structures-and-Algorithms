//天才ACM
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int maxn = 5e5+10;

ll w[maxn], t, b[maxn];
int k, n, m;

ll check(int l, int r) {
    int k = 0;
    for (int i = l; i < r; i ++ ) {
        b[k ++] = w[i];
    }
    sort(b, b + k);
    ll sum = 0;
    for (int i = 0; i < m && i < k; i ++, k --) {
        sum += 1ll*(b[i] - b[k - 1])*(b[i] - b[k - 1]);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    while (k -- ) {
        cin >> n >> m >> t;
        for (int i = 0; i < n; i ++ ) cin >> w[i];
        int l = 0, r = 0;
        int cnt = 0;
        while (r < n) {
            int len = 1;
            while (len) {
                if (r + len <= n && check(l, r + len) <= t) {
                    r += len, len <<= 1;
                }else len >>= 1;
            }
            l = r;
            cnt ++;
        }
        cout << cnt << endl;
    }

    return 0;
}