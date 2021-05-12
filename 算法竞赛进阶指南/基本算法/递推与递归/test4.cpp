//费解的开关
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;
int dic[][2] = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

string s[5];
int a[5][5], b[5][5];
int n;

void Change(int x, int y) {
    for (int i = 0; i < 5; i ++ ) {
        int x11 = x + dic[i][0];
        int y11 = y + dic[i][1];
        if (x11 >= 0 && x11 < 5 && y11 >= 0 && y11 < 5) {
            b[x11][y11] ^= 1;
        }
    }
}

int main() {
    cin >> n;
    while (n -- ) {
        for (int i = 0; i < 5; i ++ ) {
            cin >> s[i];
            for (int j = 0; j < 5; j ++ ) {
                a[i][j] = s[i][j] - '0';
            }
        }
        int cnt = INF;
        for (int i = 0; i <= 1 << 5; i ++ ) {
            int res = 0;
            int flag = 1;
            for (int j = 0; j < 5; j ++ ) {
                for (int k = 0; k < 5; k ++ ) {
                    b[j][k] = a[j][k];
                }
            }
            for (int j = 0; j < 5; j ++ ) {
                if (i >> j & 1) res ++, Change(0, j); 
            }
            for (int j = 0; j < 4; j ++ ) {
                for (int k = 0; k < 5; k ++ ) {
                    if (b[j][k] != 1) {
                        res ++;
                        Change(j + 1, k);
                    }
                }
            }
            for (int j = 0; j < 5; j ++ ) {
                if (b[4][j] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) continue;
            cnt = min(cnt, res);
        }
        if (cnt > 6) cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}