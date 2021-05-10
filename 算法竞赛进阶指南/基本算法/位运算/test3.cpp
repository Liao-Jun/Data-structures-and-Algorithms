//最短Hamilton路径
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
int INF = 0x3f3f3f3f;

int n, a[25][25];
int f[1<<20][20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> a[i][j];
        }
    }
    memset(f, INF, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1<<n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (i>>j&1) {
                for (int k = 0; k < n; k ++ ) {
                    if (i>>k&1) {
                        f[i][j] = min(f[i][j], f[i - (1<<j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    cout << f[(1<<n) - 1][n - 1] << endl;

    return 0;
}