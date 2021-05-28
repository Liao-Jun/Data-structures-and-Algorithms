#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;
const int INF = 0x3f3f3f3f;
int dic[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<char, int> m;
struct node {
    int x, y, step, flag;
};

int n;
char s[105][105];
bool used[105][105];
int x11, y11, x22, y22;

int bfs() {
    queue<node> q;
    q.push(node{x11, y11, 0, 0});
    memset(used, false, sizeof(used));
    used[x11][y11] = true;
    while (!q.empty()) {
        node N = q.front();
        q.pop();
        if (N.x == x22 && N.y == y22) return N.step;
        for (int i = 0; i < 4; i ++ ) {
            int x = N.x + dic[i][0];
            int y = N.y + dic[i][1];
            if (x >= 0 && x < n && y >= 0 && y < n && !used[x][y]) {
                if(x == x22 && y == y22) return N.step + 1;
                if (N.flag == 0 || m[s[x][y]] + N.flag == 0) {
                    used[x][y] = true;
                    q.push(node{x, y, N.step + 1, m[s[x][y]]});
                }
            }
        }
    }
    return INF;
}

int main() {
    m['+'] = 1;
    m['-'] = -1;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> s[i][j];
            if (s[i][j] == 'A') {
                x11 = i; y11 = j;
            }else if (s[i][j] == 'B') {
                x22 = i; y22 = j;
            }
        }
    }
    int cnt = bfs();
    if (cnt == INF) cout << -1 << endl;
    else cout << cnt << endl;

    return 0;
}