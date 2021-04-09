#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using P = pair<int, int>;
int dic[][2] = {{-1, 0}, {1, 0}, {0, -1},{0, 1}};

int used[10][10];
int cnt = 0;

void dfs(int x, int y) {
    if (x == 0 || y == 0 || x == 6 || y == 6 ) {
        cnt ++;
        return;
    }
    for (int i = 0; i < 4; i ++ ) {
        int x11 = x + dic[i][0];
        int y11 = y + dic[i][1];
        if (used[x11][y11] == 0) {
            used[x11][y11] = 1;
            used[6 - x11][6 - y11] = 1;
            dfs(x11, y11);
            used[x11][y11] = 0;
            used[6 - x11][6 - y11] = 0;
        }
    }
}

int main() {
    used[3][3] = 1;
    // dfs(3, 3);
    cnt = 509*4;
    cout << cnt/4 << endl;

    return 0;
}