#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;

int n, k;
int a[maxn];
stack<int> s[1005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i ++ ) {
        int t = a[i]%k;
        s[t].push(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < k; i ++ ) {
        if (!s[i].size()) continue;
        for (int j = i; j < k; j ++ ) {
            if (!s[j].size()) continue;
            int r = (k - i - j + k)%k;
            int ans1, ans2, ans3, tmp = 0;
            if (s[i].size()) {
                ans1 = s[i].top();
                s[i].pop();
                tmp += ans1;
                if (s[j].size()) {
                    ans2 = s[j].top();
                    s[j].pop();
                    tmp += ans2;
                    if (s[r].size()) {
                        ans3 = s[r].top();
                        s[r].pop();
                        tmp += ans3;
                        cnt = max(cnt, tmp);
                        s[r].push(ans3);
                    }
                    s[j].push(ans2);
                }
                s[i].push(ans1);
            }
        }
    }
    cout << cnt << endl;

    return 0;
}