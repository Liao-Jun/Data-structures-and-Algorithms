#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
using PII = pair<int, int>;
const int maxn = 1e5+10;

int n;
PII p[maxn];
vector<PII> v;

bool cmp(const PII &a, const PII &b) {
    return a.second < b.second;
}

bool check(int mid) {
    int k = 0;
    for (int i = 0; i < n; i ++ ) {
        if (p[i].first - mid <= k && p[i].second + mid >= k) {
            if (p[i].first >= k) {
                k = p[i].second - (p[i].first - k);
            } else {
                k = p[i].second + (p[i].first + k);
            }
        }
    }
    return k>= 10000;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> p[i].first >> p[i].second;
        p[i].first *= 2;
        p[i].second *= 2;
        v.push(p[i]);
    }
    sort(v, v + n, cmp);
    int l = -1, r = 20001;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l%2 == 0) cout << l/2 << endl;
    else {
        printf("%.1lf\n", l*1.0/2);
    }

    return 0;
}