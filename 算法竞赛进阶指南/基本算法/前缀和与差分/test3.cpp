//最高的牛
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 1e4 +10;

int n, p, h, m, a, b;
int d[maxn];
set<pair<int, int>> se;

int main() {
    memset(d, 0, sizeof(d));
    cin >> n >> p >> h >> m;
    while (m --) {
        cin >> a >> b;
        if (se.find(make_pair(min(a, b), max(a, b))) == se.end()) {
            se.insert(make_pair(min(a, b), max(a, b)));
        }else continue;
        for (int i = min(a, b) + 1; i < max(a, b); i ++ ) {
            d[i] -= 1;
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        cout << h + d[i] << endl;
    }

    return 0;
}