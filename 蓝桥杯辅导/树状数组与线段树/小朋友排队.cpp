#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int M = 1e6+10;

int n;
int a[M], c[M];
int sum[M];

int lowbit(int x) {
    return x&(-x);
}

void update(int x, int y) {
    while (x <= M) {
        c[x] += y;
        x += lowbit(x);
    }
}

int getsum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i ++ ) cin >> a[i], a[i] ++;
    for (int i = 0; i < n; i ++ ) {
        sum[i] = getsum(M - 1) - getsum(a[i]);
        update(a[i], 1);
    }
    memset(c, 0, sizeof(c));
    for (int i = n - 1; i >= 0; i -- ) {
        sum[i] += getsum(a[i] - 1);
        update(a[i], 1);
    }
    ll cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        cnt += 1ll*sum[i]*(sum[i] + 1)/2;
    }
    cout << cnt << endl;

    return 0;
}