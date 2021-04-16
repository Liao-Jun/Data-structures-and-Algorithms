#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

using PDD = pair<double, double>;

int INF = 0x3f3f3f3f;

int n, d;
PDD p[1005];

int main() {
    cin >> n >> d;
    bool flag = true;
    for (int i = 0; i < n; i++ ) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            flag = false;
        }
        double l = sqrt(d*d - y*y);
        p[i] = { x + l, x - l};
    }
    if (!flag) cout << -1 << endl;
    else {
        sort(p, p + n);
        int cnt = 0;
        double re = -INF;
        for (int i = 0; i < n; i ++ ) {
            if (p[i].second > re ) {
                cnt ++ ;
                re = p[i].first;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
