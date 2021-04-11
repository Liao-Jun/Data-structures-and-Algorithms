#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

using P = pair<int, int>;
int dic[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int maxn = 1005;

int n;
string s[maxn];
int used[maxn][maxn];
int cnt = 0;

void bfs(int i, int j) {
    queue<P> q;
    q.push({i, j});
    used[i][j] = 1;
    int sum = 0, res = 0;
    while(!q.empty()) {
        P p = q.front();
        q.pop();
        sum ++;
        int res1 = 0;
        for (int i = 0; i < 4; i ++ ) {
            int x = p.first + dic[i][0];
            int y = p.second + dic[i][1];
            if (x >= 0 && x < n && y >= 0 && y < n && used[x][y] == 0) {
                if (s[x][y] == '.') res1 ++;
                else {
                    q.push({x, y});
                    used[x][y] = 1;
                }
            }
        }
        if (res1 > 0) res ++;
    }
    if (sum == res) cnt ++;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> s[i];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (s[i][j] == '#' && used[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}