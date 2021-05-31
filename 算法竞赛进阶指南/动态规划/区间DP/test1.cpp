//石子合并
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;

int n, w[310];
int f[310][310];

int main() {
    cin >> n;
    memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
        w[i] += w[i - 1];
        f[i][i] = 0;
    }
    for (int len = 2; len <= n; len ++ ) {
        for (int i = 1; i + len - 1 <= n; i ++ ) {
            int j = i + len - 1;
            for (int k = i; k <= j - 1; k ++ ) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + w[j] - w[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;

    return 0;
}