//分级
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int INF = 0x3f3f3f3f;
const int maxn = 2010;

int n;
int a[maxn], b[maxn], f[maxn][maxn];

int work() {
    for (int i = 1; i <= n; i ++ ) b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int Min = INF;
        for (int j = 1; j <= n; j ++ ) {
            Min = min(Min, f[i - 1][j]);
            f[i][j] = Min + abs(a[i] - b[j]);
        }
    }
    int res = INF;
    for (int i = 1; i <= n; i ++ ) res = min(res, f[n][i]);
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    int res = work();
    reverse(a + 1, a + n + 1);
    res = min(res, work());
    cout << res << endl;

    return 0;
}