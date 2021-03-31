#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const int M = 1e5+10;

int n, k;
ll a[M], b[M];

int main() {
    cin >> n >> k;
    a[0] = 0;
    memset(b, 0, sizeof(b));
    ll cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        a[i] += a[i - 1];
        a[i] %= k;
        cnt += b[a[i]];
        b[a[i]] ++;
    }
    cout << cnt + b[0] << endl;

    return 0;
}