#include <iostream>

using namespace std;

int t, m, n;
int f[25][25];

int main() {
    cin >> t;
    while (t --) {
        cin >> m >> n;
        for (int i = 0; i < 22; i ++ ) f[0][i] = 1;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                f[i][j] = f[i][j - 1];
                if (i >= j) {
                    f[i][j] += f[i - j][j];
                }
            }
        }
        cout << f[m][n] << endl;
    }

    return 0;
}