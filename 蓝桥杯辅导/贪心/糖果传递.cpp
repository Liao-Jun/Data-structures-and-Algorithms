#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int maxn = 1e6+10;

int n;
ll a[maxn];
ll c[maxn];

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];
    ll avg = sum/n;
    for (int i = 1; i <= n; i ++ ) {
        c[i] = a[i] + c[i - 1] - avg;
    }
    sort(c + 1, c + n + 1);
    ll cnt = 0;
    ll mid = c[(n >> 1) + 1];
    for (int i = 1; i <= n; i ++ ) {
        cnt += abs(c[i] - mid);
    }
    cout << cnt << endl;

    return 0;
}