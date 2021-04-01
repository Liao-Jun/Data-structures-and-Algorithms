#include <iostream>

using namespace std;

int t, r, c, m;
int a[1005][1005], sum[1005][1005];

int main() {
    cin >> t;
    while (t -- ) {
        cin >> r >> c;
        for (int i = 1; i <= r; i ++ ) {
            for (int j = 1; j <= c; j ++ ) {
                cin >> a[i][j];
            }
        }
        sum[1][1] = a[1][1];
        for (int i = 1; i <= r; i ++ ) {
            for (int j = 1; j <= c; j ++ ) {
                if (i == 1 && j == 1 ) continue;
                if (i == 1) sum[i][j] = sum[i][j - 1] + a[i][j];
                else if (j == 1) sum[i][j] = sum[i - 1][j] + a[i][j];
                else sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + a[i][j];
            }
        }
        cout << sum[r][c] << endl;
    }

    return 0;
}