#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;

int n;
int a[maxn];
int d[maxn];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    if (a[0] == a[n - 1]) {
        cout << n << endl;
        return 0;
    }
    for (int i = 1; i < n; i ++ ) d[i] = a[i] - a[i - 1];
    int g = d[1];
    for (int i = 2; i < n; i ++) {
        g = gcd(d[i], g);
    }
    cout << (a[n - 1] - a[0])/g + 1 << endl;

    return 0;
}