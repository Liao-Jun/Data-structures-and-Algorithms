#include <iostream>
#include <cstring>

using namespace std;

int n, m, q, x11, x22, y11, y22;
int a[1005][1005];

int main() {
    memset(a, 0, sizeof(a));
    int x;
    cin >> n >> m >> q;
    for (int i = 1; i <= n ; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            cin >> x;
            a[i][j] = a[i - 1][j] + a[i][j - 1] + x - a[i-1][j-1];
        }
    }
    while (q -- ) {
        cin >> x11 >> y11 >> x22 >> y22;
        cout << a[x22][y22] + a[x11-1][y11-1] - a[x11-1][y22] - a[x22][y11-1] << endl;
    }

    return 0;
}