//数字组合
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int f[10010];

int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        cin >> x;
        for (int j = m; j >= x; j -- ) f[j] += f[j - x];
    }
    cout << f[m] << endl;

    return 0;
}