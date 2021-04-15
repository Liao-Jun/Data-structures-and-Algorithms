#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct node {
    int x, y, step;
    node (int _x, int _y, int _step):x(_x), y(_y), step(_step){}
};

int dic[][2] = {{-1, 0}, {1, 0},{0, 1}, {0, -1}};

char s[205][205];
int r, c;
int x11, y11, x22, y22;
int used[205][205];

int bfs() {
    queue<node> q;
    q.push(node(x11, y11, 0));
    memset(used, 0, sizeof(used));
    used[x11][y11] = 1;
    while(!q.empty()) {
        node N = q.front();
        q.pop();
        if (x22 == N.x && y22 == N.y) {
            return N.step;
        }
        for (int i = 0; i < 4; i ++ ) {
            int x = N.x + dic[i][0];
            int y = N.y + dic[i][1];
            if (x >= 0 && x < r && y >= 0 && y < c && used[x][y] == 0 && (s[x][y] == '.' || s[x][y] == 'E')) {
                q.push(node(x, y, N.step + 1));
                used[x][y] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> r >> c;
        for (int i = 0; i < r; i ++ ) {
            for (int j = 0; j < c; j ++ ) {
                cin >> s[i][j];
                if (s[i][j] == 'S') {
                    x11 = i;
                    y11 = j;
                }else if(s[i][j] == 'E') {
                    x22 = i;
                    y22 = j;
                }
            }
        }
        int cnt = bfs();
        if (cnt == 0) cout << "oop!" << endl;
        else cout << cnt << endl;
    }

    return 0;
}