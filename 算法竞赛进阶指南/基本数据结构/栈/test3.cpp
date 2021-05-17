//火车进栈
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n, cnt = 0, A = 0, B = 0;
int a[30], b[30];

void dfs(int i) {
    if (i == n + 1) {
        if (++cnt > 20) return;
        for (int i = 1; i <= A; i ++ ) cout << a[i];
        for (int i = B; i; i -- ) cout << b[i];
        cout << endl;
        return;
    }
    if (B) {
        cout << B << ' ';
        a[++ A] = b[B --];
        dfs(i);
        b[++ B] = a[A --];
    }
    b[++ B] = i;
    dfs(i + 1);
    -- B;
}

int main() {
    cin >> n;
    dfs(1);

    return 0;
}