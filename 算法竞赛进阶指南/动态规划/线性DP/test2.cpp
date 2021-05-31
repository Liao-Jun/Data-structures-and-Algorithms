//最长公共上升子序列
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 3010;

int n;
int a[maxn], b[maxn];
int f[maxn][maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i ++ ) {
        int Max = 1;
        for (int j = 1; j <= n; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], Max);
            if (a[i] > b[j]) Max = max(Max, f[i - 1][j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
    cout << res << endl;

    return 0;
}