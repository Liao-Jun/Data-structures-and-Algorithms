//选课
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 310;

int n, m;
vector<int> v[310];
int dp[310][310];
int w[310];

void dfs(int u) {
    for (int i = 0; i < v[u].size(); i ++ ) {
        int x = v[u][i];
        dfs(x);
        for (int j = m; j >= 0; j -- ) {
            for (int k = 0; k <= j; k ++ ) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[x][k]);
            }
        }
    }
    if (u != 0) {
        for (int i = m; i >= 1; i -- ) {
            dp[u][i] = dp[u][i - 1] + w[u];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(i);
        w[i] = y;
    }
    dfs(0);
    cout << dp[0][m] << endl;

    return 0;
}