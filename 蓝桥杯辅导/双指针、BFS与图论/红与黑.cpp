#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

using P = pair<int, int>;

int dic[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char c[25][25];
int w, h;
int x11, y11;

int bfs() {
    queue<P> q;
    q.push({x11, y11});
    int cnt = 1;
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++ ) {
            int x = p.first + dic[i][0];
            int y = p.second + dic[i][1];
            if (x >= 0 && x < h && y >= 0 && y < w && c[x][y] == '.') {
                q.push({x, y});
                cnt ++;
                c[x][y] = '#';
            }
        }
    }
    return cnt;
}

int main() {
    while (cin >> w >> h && (w != 0 && h != 0)) {
        for (int i = 0; i < h; i ++ ) {
            for (int j = 0; j < w; j ++ ) {
                cin >> c[i][j];
                if (c[i][j] == '@') {
                    x11 = i;
                    y11 = j;
                }
            }
        }
        cout << bfs() << endl;
    }

    return 0;
}