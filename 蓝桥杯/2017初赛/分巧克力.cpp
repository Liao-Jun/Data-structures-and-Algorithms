#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e5+10;

int n, k;
int h[M], w[M];

bool judge(int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        int a = h[i]/mid;
        a *= w[i]/mid;
        cnt += a;
    }
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    int l = 1, r = 100000;
    for (int i = 0;i < n; i ++ ) {
        cin >> h[i] >> w[i];
    }
    while (r > l) {
        int mid = r + l >> 1;
        if (judge(mid)) l = mid + 1;
        else r = mid;
    }
    cout << r - 1 << endl;

    return 0;
}