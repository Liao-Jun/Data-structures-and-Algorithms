#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
struct node {
    int a, b;
};

int n, a, b;
vector<node> v;

bool cmp(const node &a, const node &b) {
    return a.b < b.b;
}

bool check(int mid) {
    int k = 0;
    vector<node> v1(v);
    while(1) {
        bool found = false;
        for (int i = 0; i < v1.size(); i ++ ) {
            if (v1[i].a - mid <= k && k <= v1[i].b + mid) {
                found = true;
                if (v1[i].a + mid >= k) k += (v1[i].b - v1[i].a);
                else k = v1[i].b + mid;
                v1.erase(v1.begin() + i);
                break;
            }
        }
        if (!found || k >= 20000) break;
    }
    return k >= 20000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a >> b;
        a *= 2;
        b *= 2;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int l = 0, r = 20000;
    double re = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, re = mid;
        else l = mid + 1;
    }
    re /= 2.0;
    cout << re << endl;

    return 0;
}