//防晒
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 2500 + 10;

int c, l;
pair<int, int> spf[maxn];
int spfs[1000+10];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    cin >> c >> l;
    for (int i = 0; i < c; i ++ ) {
        cin >> spf[i].first >> spf[i].second;
    }
    sort(spf, spf + c, cmp);
    memset(spfs, 0, sizeof(spfs));
    for (int i = 0; i < l; i ++ ) {
        int a, b;
        cin >> a >> b;
        spfs[a] += b;
    }
    int cnt = 0;
    for (int i = 0; i < c; i ++ ) {
        for (int j = spf[i].second; j >= spf[i].first; j -- ) {
            if (spfs[j] > 0) {
                cnt ++;
                spfs[j] --;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}