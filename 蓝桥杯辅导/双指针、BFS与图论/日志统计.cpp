#include <iostream>
#include <algorithm>

using namespace std;

using P = pair<int, int>;

const int maxn = 1e5+10;

int n, k, d;
P p[maxn];
int cnt[maxn], f[maxn];

int main() {
    cin >> n >> d >> k;
    for (int i = 0; i < n; i ++ ) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    int j = 0;
    for (int i = 0; i < n; i ++ ) {
        int id = p[i].second;
        cnt[id] ++;
        while (p[i].first - p[j].first >= d) {
            cnt[p[j].second] --;
            j ++;
        }
        if (cnt[id] >= k) f[id] = 1;
    }
    for (int i = 0; i < maxn; i ++ ) {
        if (f[i] == 1) cout << i << endl;
    }

    return 0;
}