#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll n;
ll f[1000];

int main() {
    f[0] = 1;
    for (int i = 1; i <= 20; i ++ ){
        f[i] = f[i - 1]*i;
    }
    while (cin >> n) {
        ll len = 0, sum = 1;
        for (int i = 2; i*i <= n; i ++ ) {
            int cnt = 0;
            if (n%i == 0) {
                while (n%i == 0) {
                    n /= i;
                    cnt ++;
                }
                len += cnt;
                sum *= f[cnt];
            }
        }
        if (n > 1) len ++;
        cout << len << ' ' << f[len]/sum << endl;
    }

    return 0;
}