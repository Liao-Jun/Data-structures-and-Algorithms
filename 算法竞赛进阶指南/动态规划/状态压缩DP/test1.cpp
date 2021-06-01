//蒙德里安的梦想
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 12, M = 1 << N;

int n, m;
ll f[N][M];
bool st[M];

int main() {
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        for (int i = 0; i < 1 << n; i ++ ) {
            st[i] = true;
            int cnt = 0;
            for (int j = 0; j < n; j ++ ) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        st[i] = false;
                    }
                    cnt = 0;
                }else {
                    cnt ++;
                }
            }
            if (cnt & 1) {
                st[i] = false;
            }
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ ) {
            for (int j = 0; j < 1 << n; j ++ ) {
                for (int k = 0; k < 1 << n; k ++ ) {
                    if (!(j & k) && st[j | k]) {
                        f[i][k] += f[i - 1][j];
                    }
                }
            }
        }
        cout << f[m][0] << endl;
    }

    return 0;
}