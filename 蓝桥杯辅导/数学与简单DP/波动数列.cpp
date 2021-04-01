#include <iostream>

using namespace std;

using ll = long long;
const int Mod = 100000007;

int n, s, a, b;
ll f[1005][1005];

int get(int x, int y) {
    return (x%y + y)%y;
}

int main() {
    cin >> n >> s >> a >> b;
    f[0][0] = 1;
    for (int i = 1; i <= n - 1; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            f[i][j] = (f[i - 1][get(j - (n - i)*a, n)] + f[i - 1][get(j + (n - i)*b,n)])%Mod;
        }
    }
    cout << f[n - 1][get(s, n)]%Mod << endl;

    return 0;
}