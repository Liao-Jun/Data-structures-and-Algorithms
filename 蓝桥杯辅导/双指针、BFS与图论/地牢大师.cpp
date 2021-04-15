#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int x, y, z, steps;
    node(int _x, int _y, int _z, int _steps):x(_x), y(_y), z(_z), steps(_steps){}
};

int dic[][3] = {{0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 1, 0}};

int l, r, c;
int used[105][105][105];
char s[105][105][105];
int x11, y11, z11, x22, y22, z22;

int bfs(){
    queue<node> q;
    q.push(node(x11, y11, z11, 0));
    memset(used, 0, sizeof(used));
    used[x11][y11][z11] = 1;
    while (!q.empty()) {
        node N = q.front();
        q.pop();
        if (N.x == x22 && N.y == y22 && N.z == z22) {
            return N.steps;
        }
        for (int i = 0; i < 6; i ++ ) {
            int x = N.x + dic[i][0];
            int y = N.y + dic[i][1];
            int z = N.z + dic[i][2];
            if (x >= 0 && x < l && y >= 0 && y < r && z >= 0 && z < c && used[x][y][z] == 0 && (s[x][y][z] == '.' || s[x][y][z] == 'E')) {
                q.push(node(x, y, z, N.steps + 1));
                used[x][y][z] = 1;
            }
        }
    }
    return 0;
}

int main() {
    while (cin >> l >> r >> c && !(l == 0 && r == 0 && c == 0)) {
        for (int i = 0; i < l; i ++ ) {
            for (int j = 0; j < r; j ++ ) {
                for (int k = 0; k < c; k ++ ) {
                    cin >> s[i][j][k];
                    if (s[i][j][k] == 'S') {
                        x11 = i;
                        y11 = j;
                        z11 = k;
                    }else if (s[i][j][k] == 'E') {
                        x22 = i;
                        y22 = j;
                        z22 = k;
                    }
                }
            }
        }
        int cnt = bfs();
        if (cnt == 0) cout << "Trapped!" << endl;
        else cout << "Escaped in " << cnt << " minute(s)." << endl;
    }

    return 0;
}