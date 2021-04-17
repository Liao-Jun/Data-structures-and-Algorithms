#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;

bool st[maxn];
int prime[maxn], cnt;
int re[maxn], len;

void get_prime() {
    for (int i = 2; i <= maxn; i ++ ) {
        if (!st[i]) prime[cnt ++] = i;
        for (int j = 0; prime[j]*i <= maxn; j ++ ) {
            st[prime[j]*i] = true;
            if (i%prime[j] == 0) break;
        }
    }
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; i ++ ) {
        if (x%i == 0) return false;
    }
    return true;
}

void dfs(int l, int result, int s) {
    if (s == 1) {
        re[len ++] = result;
        return;
    }
    if (s - 1 > (l < 0 ? 1 : prime[l]) && is_prime(s - 1)) {
        re[len ++] = result*(s - 1);
    }
    for (int i = l + 1; prime[i]*prime[i] <= s; i ++ ) {
        int p = prime[i];
        for (int j = 1 + p, t = p; j <= s; t *= p, j += t) {
            if (s%j == 0) dfs(i, result*t, s/j);
        }
    }
}

int main() {
    get_prime();
    int s;
    while (cin >> s) {
        len = 0;
        dfs(-1, 1, s);
        cout << len << endl;
        if (len) {
            sort(re, re + len);
            for (int i = 0; i < len; i ++ ) {
                cout << re[i] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}