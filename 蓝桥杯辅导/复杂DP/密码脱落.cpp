#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int dp[1010][1010];

int main() {
    cin >> s;
    for (int len = 1; len <= s.length(); len ++ ) {
        for (int l = 0; l + len -1 < s.length(); l ++ ) {
            int r = l + len - 1;
            if (len == 1) dp[l][r] = 1;
            else {
                if (s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1] + 2;
                if (dp[l][r - 1] > dp[l][r]) dp[l][r] = dp[l][r - 1];
                if (dp[l + 1][r] > dp[l][r]) dp[l][r] = dp[l + 1][r];
            }
        }
    }
    cout << s.length() - dp[0][s.length() - 1];

    return 0;
}