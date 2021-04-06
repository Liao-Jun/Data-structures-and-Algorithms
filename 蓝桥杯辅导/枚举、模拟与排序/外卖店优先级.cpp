#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

using P = pair<int, int>;
const int M = 1e5+10;

int n, m, t;
int f[M];
int last[M];
int flag[M];
P p[M];

bool cmp(const P &a, const P &b) {
    return a.first <= b.first;
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < m; i ++ ) {
        // cin >> p[i].first >> p[i].second;
        scanf("%d%d",&p[i].first, &p[i].second);
    }
    int cnt = 0;
    sort(p, p + m, cmp);
    memset(f, 0, sizeof(f));
    memset(last, 0, sizeof(last));
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < m; i ++ ) {
        if (p[i].first - last[p[i].second] - 1 >= f[p[i].second]) {
            f[p[i].second] = 2, last[p[i].second] = p[i].first;
            if (flag[p[i].second] == 1) cnt --, flag[p[i].second] = 0;
        }else if (last[p[i].second] == p[i].first) {
            f[p[i].second] += 2;
            last[p[i].second] = p[i].first;
            if (f[p[i].second] >= 6 && flag[p[i].second] == 0) cnt ++, flag[p[i].second] = 1;  
        }else {
            f[p[i].second] -= (p[i].first - last[p[i].second] - 1);
            f[p[i].second] += 2;
            last[p[i].second] = p[i].first;
            if (f[p[i].second] >= 6 && flag[p[i].second] == 0) cnt ++, flag[p[i].second] = 1;
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        if (last[i] != t) {
            f[i] -= (t - last[i]);
            if (f[i] <= 3 && flag[i] == 1) cnt --;
        }
    }
    cout << cnt << endl;

    return 0;
}