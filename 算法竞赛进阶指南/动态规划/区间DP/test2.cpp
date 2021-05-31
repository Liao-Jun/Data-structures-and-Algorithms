//多边形
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;

int n, num[105], maxdp[105][105], mindp[105][105];
char c[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> c[i] >> num[i];
        c[i + n] = c[i];
        num[i + n] = num[i];
    }
    for (int i = 1; i <= 2*n; i ++ ) {
        for (int j = 1; j <= 2*n; j ++ ) {
            if(i == j) {
                maxdp[i][j] = num[i];
                mindp[i][j] = num[i];
            }else {
                maxdp[i][j] = -INF;
                mindp[i][j] = INF;
            }
        }
    }
    for (int len = 2; len <= n; len ++ ) {
        for (int i = 1; i + len - 1 <= 2*n; i ++ ) {
            int j = i + len - 1;
            for (int k = i; k <= j - 1; k ++ ) {
                if(c[k + 1] == 'x') {
                    maxdp[i][j] = max(maxdp[i][j], max(maxdp[i][k]*maxdp[k + 1][j], mindp[i][k]*mindp[k + 1][j]));
                    mindp[i][j] = min(mindp[i][j], min(min(mindp[i][k]*maxdp[k + 1][j], maxdp[i][k]*mindp[k + 1][j]), mindp[i][k]*mindp[k + 1][j]));
                }else {
                    maxdp[i][j] = max(maxdp[i][j], maxdp[i][k] + maxdp[k + 1][j]);
                    mindp[i][j] = min(mindp[i][j], (mindp[i][k] + mindp[k + 1][j]));
                }
            }
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; i ++ ) {
        res = max(res, maxdp[i][i + n - 1]);
    }
    cout << res << endl;
    for (int i = 1; i <= n; i ++ ) {
        if (maxdp[i][i + n - 1] == res ) {
            cout << i << ' ';
        }
    }

    return 0;
}