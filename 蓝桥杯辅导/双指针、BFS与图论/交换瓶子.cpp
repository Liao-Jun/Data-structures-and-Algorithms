#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e4+10;

int n;
int a[maxn];
bool f[maxn];

int main() {
    cin >> n;
    int cnt = 0;
    memset(f, false, sizeof(f));
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) {
        if (!f[i]) {
            cnt ++;
            for (int j = i; !f[j]; j = a[j]) {
                f[j] = true;
            }
        }
    }
    cout << n - cnt << endl;

    return 0;
}