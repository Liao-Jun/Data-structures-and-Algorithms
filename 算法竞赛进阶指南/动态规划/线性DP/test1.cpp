//杨老师的照相排列
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int N = 31;

int k, s[6];
ll f[N][N][N][N][N];

int main() {
    while (cin >> k && k != 0) {
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        f[0][0][0][0][0] = 1;
        for (int i = 0; i < k; i ++ ) cin >> s[i];
        for (int i = 0; i <= s[0]; i ++ ) {
            for (int j = 0; j <= min(i, s[1]); j ++ ) {
                for (int k = 0; k <= min(j, s[2]); k ++ ) {
                    for (int h = 0; h <= min(k, s[3]); h ++ ) {
                        for (int l = 0; l <= min(h, s[4]); l ++ ) {
                            ll &x = f[i][j][k][h][l];
                            if (i && i - 1 >= j) x += f[i - 1][j][k][h][l];
                            if (j && j - 1 >= k) x += f[i][j - 1][k][h][l];
                            if (k && k - 1 >= h) x += f[i][j][k - 1][h][l];
                            if (h && h - 1 >= l) x += f[i][j][k][h - 1][l];
                            if (l) x += f[i][j][k][h][l - 1];
                        }
                    }
                }
            }
        }
        cout << f[s[0]][s[1]][s[2]][s[3]][s[4]] << endl;
    }

    return 0;
}