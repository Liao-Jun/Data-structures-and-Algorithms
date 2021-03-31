#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, r;
int a[5005][5005];

int main() {
    cin >> n >> r;
    memset(a, 0, sizeof(a));
    int x, y, w;
    while (n -- ) {
        cin >> x >> y >> w;
        a[x + 1][y + 1] += w;
    }
    for (int i = 1; i < 5002; i ++ ) {
        for (int j = 1; j < 5002; j ++ ) {
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }
    }
    int Max = 0;
    for (int i = r; i < 5002; i ++ ) {
        for (int j = r; j < 5002; j ++ ) {
            Max = max(Max,a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r]);
        }
    }
    cout << Max << endl;

    return 0;
}