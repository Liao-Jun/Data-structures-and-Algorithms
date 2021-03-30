#include <iostream>
#include <string>

using namespace std;
int INF = 0x3f3f3f3f;

string s[6];
int a[6][6], b[6][6];
int dic[][2] = {{1,0},{-1,0},{0,1},{0,-1},{0,0}};

void turn(int x, int y) {
    for (int i = 0; i < 5; i ++ ) {
        int dx = x + dic[i][0];
        int dy = y + dic[i][1];
        if (dx >= 0 && dy >= 0 && dy < 5 && dx < 5) {
            b[dx][dy] ^= 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t -- ){
        for (int i = 0; i < 5; i ++ ) {
            cin >> s[i];
            for (int j = 0; j < 5; j ++ ) {
                a[i][j] = s[i][j] - '0';
            }
        }
        int cnt = INF;
        for (int i = 0; i < 32; i ++ ) {
            int res = 0;
            int flag = 0;
            for (int j = 0; j < 5; j ++ ) {
                for (int k = 0; k < 5; k ++ ) {
                    b[j][k] = a[j][k];
                }
            }
            for (int j = 0; j < 5; j ++ ) {
                if (i >> j & 1) {
                    res ++;
                    turn(0, j);
                }
            }
            for (int j = 0; j < 4; j ++ ) {
                for (int k = 0; k < 5; k ++ ) {
                    if (b[j][k] != 1) {
                        res ++;
                        turn(j+1, k);
                    }  
                }
            }
            for (int j = 0; j < 5; j ++ ) {
                if (b[4][j] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            else cnt = min (cnt, res);
        }
        if (cnt > 6) cout << -1 << endl;
        else cout << cnt << endl;
    }

    return 0;
}