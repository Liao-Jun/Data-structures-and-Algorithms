//畜栏预定
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
using PII = pair<int, int>;
const int maxn = 5e4+10;

int n;
pair<PII, int> e[maxn];
int r[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> e[i].first.first >> e[i].first.second;
        e[i].second = i;
    }
    sort(e + 1, e + 1 + n);
    priority_queue<PII, vector<PII>, greater<PII>> p;
    for (int i = 1; i <= n; i ++ ) {
        if (p.empty() || p.top().first >= e[i].first.first) {
            PII s = make_pair(e[i].first.second, p.size());
            r[e[i].second] = s.second;
            p.push(s);
        }else {
            auto s = p.top();
            p.pop();
            s.first = e[i].first.second;
            r[e[i].second] = s.second;
            p.push(s);
        }
    }
    cout << p.size() << endl;
    for (int i = 1; i <= n; i ++) {
        cout << r[i] + 1 << endl;
    }

    return 0;
}