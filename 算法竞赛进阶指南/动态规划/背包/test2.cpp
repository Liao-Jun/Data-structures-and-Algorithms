//自然数拆分
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int Mod = 2147483648;

int n;
ll f[4010];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < n; i ++ ) {
        for (int j = i; j <= n; j ++ ) {
            f[j] = (f[j] + f[j - i]) % Mod;
        }
    }
    cout << f[n] << endl;

    return 0;
}