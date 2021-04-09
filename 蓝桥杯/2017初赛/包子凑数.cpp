#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[105];
int dp[11000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    int g = a[0];
    for (int i = 1; i < n; i ++ ) g = __gcd(g, a[i]);
    if (g != 1){
        cout << "INF" << endl;
        return 0;
    }
    for (int i = 0; i < n; i ++ ) {
        dp[a[i]] = 1;
        for (int j = 0; j + a[i] < 10000; j ++){
            if (dp[j]) {
                dp[a[i] + j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < 10000; i ++) {
        if (!dp[i]) cnt ++;
    }
    cout << cnt << endl;

    return 0;
}