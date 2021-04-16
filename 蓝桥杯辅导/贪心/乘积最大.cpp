#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int Mod = 1000000009;
const int maxn = 1e5+10;

int n, k;
ll a[maxn];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll sum = 1;
    int l = 0, r = n - 1;
    int flag = 1;
    if (k%2 == 1) {
        sum = a[r];
        r --;
        k --;
        if (sum < 0) flag = -1;
    }
    while (k > 0) {
        ll L = a[l]*a[l + 1];
        ll R = a[r]*a[r - 1];
        if (flag*L > flag*R) {
            sum = L%Mod*sum%Mod;
            l += 2;
        }else {
            sum = R%Mod*sum%Mod;
            r -= 2;
        }
        k -= 2;
    }
    cout << sum << endl;

    return 0;
}