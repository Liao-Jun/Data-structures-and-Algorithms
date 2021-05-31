//没有上司的舞会
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 6010;

int n, root, h[maxn], f[maxn], dp[2][maxn], ind[maxn], used[maxn];

void dfs(int x) {
    if (!x) return;
    used[x] = 1;
    root = x;
    dp[0][f[x]] += max(dp[1][x] + h[x], dp[0][x]);
    dp[1][f[x]] += dp[0][x];
    ind[f[x]] --;
    if (!ind[f[x]]) dfs(f[x]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    int a, b;
    for (int i = 1; i < n; i ++ ) {
        cin >> a >> b;
        f[a] = b;
        ind[b] ++;
    }
    for (int i = 1; i <= n; i ++ )
        if (!used[i] && !ind[i])
            dfs(i);
    cout << max(dp[0][root], dp[1][root] + h[root]) << endl;

    return 0;
}