#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 105;

int f[maxn][maxn];
int n, k;

int main() {
    cin >> n >> k;
    int w;
    memset(f, -INF, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> w;
        for (int j = 0; j <= k; j ++ ) {
            f[i][j] = f[i - 1][j];
            f[i][j] = max(f[i][j], f[i - 1][(j - w%k + k)%k] + w);
        }
    }
    cout << f[n][0] << endl;

    return 0;
}