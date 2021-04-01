#include <iostream>
#include <algorithm>

using namespace std;

const int Mod = 1000000007;

int n, m, k;
int a[55][55];
int f[55][55][15][15];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            cin >> a[i][j];
        }
    }
    f[1][1][0][0] = 1;
    f[1][1][1][a[1][1]] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            for (int K = 0; K <= k; K ++ ) {
                for (int h = 0; h <= 12; h ++ ) {
                    f[i][j][K][h] = (f[i][j][K][h] + f[i - 1][j][K][h] + f[i][j - 1][K][h])%Mod;
                    if (h == a[i][j]) {
                        for (int l = 0; l < h; l ++ ) {
                            f[i][j][K][h] = (f[i][j][K][h] + f[i - 1][j][K - 1][l] + f[i][j - 1][K - 1][l])%Mod;
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 12; i ++ ) {
        cnt = (cnt + f[n][m][k][i])%Mod;
    }
    cout << cnt << endl;

    return 0;
}