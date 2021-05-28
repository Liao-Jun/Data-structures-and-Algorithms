#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e6 + 10;
int f[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = 0;
    for (int i = 2; i <= n; i ++ ) {
        f[i] = (f[i - 1] + k)%i;
    }
    cout << f[n] + 1 << endl;

    return 0;
}