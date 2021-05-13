//最佳牛围栏
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int f, n;
int a[maxn];
double d[maxn];

bool check(double mid) {
    for (int i = 1; i <= n; i ++ ) d[i] = d[i - 1] + a[i] -mid;
    double Min = INF;
    for (int i = 0, j = f; j <= n; i ++, j ++ ) {
        Min = min(Min, d[i]);
        if (d[j] >= Min) return true; 
    }
    return false;
}

int main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    double l = 0, r = 2000;
    while (r - l > 1e-5) {
        double mid = (r + l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)(r*1000) << endl;

    return 0;
}