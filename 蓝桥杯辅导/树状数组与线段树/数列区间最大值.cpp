#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int M = 1e5+10;

int dp[M][34];
int n, m;

int query(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1<<k) + 1][k]);
}

int main() {
    scanf("%d%d",&n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d",&dp[i][0]);
    int t = log(n)/log(2) + 1;
    for (int j = 1; j < t; j ++ ) 
        for (int i = 1; i <= n - (1<<j) + 1; i ++ ) 
            dp[i][j] = max(dp[i][j - 1], dp[i + (1<<(j - 1))][j - 1]);
    int x, y;
    while (m --) {
        scanf("%d%d",&x, &y);
        printf("%d\n",query(x, y));
    }

    return 0;
}