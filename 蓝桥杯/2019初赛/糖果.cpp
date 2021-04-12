#include <iostream>
#include <cstring>

using namespace std;

int dp[1<<20];
int st[100];
int n, m, k;

int main() {
    cin >> n >> m >> k;
    int re = (1<<m) - 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i ++ ) {
        int s = 0;
        for (int j = 0; j < k; j ++ ) {
            int x;
            cin >> x;
            s |= (1<<x - 1);
        }
        dp[s] = 1;
        st[i] = s;
    }
    for (int i = 0; i <= re; i ++ ) {
        if (dp[i] != -1 ) {
            for (int j = 0; j < n; j ++ ) {
                int s = st[j];
                if (dp[i|s] == -1 || dp[i|s] > dp[i] + 1) {
                    dp[i|s] = dp[i] + 1;
                }
            }
        }
    }
    cout << dp[re] << endl;

    return 0;
}