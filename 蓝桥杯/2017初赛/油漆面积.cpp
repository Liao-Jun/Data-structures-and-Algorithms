#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M =1e4+10;

bool a[M][M];
long long cnt = 0;

int main() {
    int n;
    scanf("%d", &n);
    int x11, y11, x22, y22;
    memset(a, 0, sizeof(a));
    cnt = 0;
    while (n --) {
        scanf("%d%d%d%d", &x11, &y11, &x22, &y22);
        if (x11 > x22) swap(x11, x22);
        if (y11 > y22) swap(y11, y22);
        for (int i = x11; i < x22; i ++ ) {
            for (int j = y11; j < y22; j ++ ) {
                if (!a[i][j]) {
                    cnt ++;
                    a[i][j] = 1;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}