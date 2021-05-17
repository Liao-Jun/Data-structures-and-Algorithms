//雷达设备
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
using PDD = pair<double, double>;
const int INF = 0x3f3f3f3f;

int n, d;
double x, y;
PDD p[1010];

int main() {
    cin >> n >> d;
    bool flag = true;
    for (int i = 0; i < n; i ++ ) {
        cin >> x >> y;
        if (y > d) flag = false;
        else p[i] = make_pair(x + sqrt(d*d - y*y), x - sqrt(d*d - y*y));
    }
    int cnt = 0;
    double f = -INF;
    if (!flag) cout << -1 << endl;
    else {
        sort(p, p + n);
        for (int i = 0; i < n; i ++ ) {
            if (p[i].second > f) {
                cnt ++;
                f = p[i].first;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}