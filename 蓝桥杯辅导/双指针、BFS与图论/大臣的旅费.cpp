#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

using ll = long long;

const int maxn = 1e5+10;

struct node{
    int to, d;
    node (int _to, int _d):to(_to), d(_d){}
};

int n;
vector<node> ed[maxn];
int dist[maxn];

void dfs(int u, int fa, int d) {
    dist[u] = d;
    for (auto node : ed[u]) {
        if (node.to != fa) {
            dfs(node.to, u, dist[u] + node.d);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].push_back({b, c});
        ed[b].push_back({a, c});
    }
    dfs(1, -1, 0);
    int u = 1;
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] > dist[u]) {
            u = i;
        }
    }
    dfs(u, -1, 0);
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] > dist[u]) {
            u = i;
        }
    }
    ll s = 1ll*dist[u];
    cout << (21 + s)*s/2 << endl;

    return 0;
}