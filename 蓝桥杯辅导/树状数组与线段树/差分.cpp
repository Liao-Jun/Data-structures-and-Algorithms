#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;

int n, m;
int a[maxn], c[maxn];

int main() {
    cin >> n >> m;
    cin >> a[0];
    c[0] = a[0];
    for (int i = 1; i < n; i ++ ) {
        cin >> a[i];
        c[i] = a[i] - a[i - 1];
    }
    int l, r, s;
    for (int i = 0; i < m; i ++ ){
        cin >> l >> r >> s;
        c[l - 1] += s;
        c[r] -= s;
    }
    cout << c[0];
    for (int i = 1; i < n; i ++ ) {
        c[i] += c[i - 1];
        cout << ' ' << c[i];
    }
    cout << endl;

    return 0;
}