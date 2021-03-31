#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e5+10;

int n, k;
pair<int, int> P[M];

bool judge(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        int a = P[i].first/x;
        int b = P[i].second/x;
        cnt += a*b;
    }
    if (cnt >= k) return true;
    else return false;
}

int main() {
    cin >> n >> k;
    int maxP = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> P[i].first >> P[i].second;
        if (P[i].first < P[i].second) swap(P[i].first, P[i].second);
        maxP = max(maxP, P[i].first);
    }
    int l = 0, r = maxP;
    while (r - l > 2) {
        int mid = l + r >> 1;
        if(judge(mid)) l = mid;
        else r = mid + 1;
    }
    cout << l << endl;

    return 0;
}