//激光炸弹
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, r, x, y, w;
int a[5005][5005];

int main () {
    cin >> n >> r;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i ++ ) {
        cin >> x >> y >> w;
        a[x + 1][y + 1] += w;
    }
    for (int i = 1; i < 5005; i ++ ) {
        for (int j = 1; j < 5005; j ++ ) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }
    }
    int res = 0;
    for (int i = r; i < 5005; i ++ ) {
        for (int j = r; j < 5005; j ++ ) {
            res = max(res, a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r]);
        }
    }
    cout << res << endl;

    return 0;
}