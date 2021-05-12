//奇怪的汉诺塔
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int f[20], d[20];

int main() {
    d[1] = 1;
    for (int i = 2; i <= 12; i ++ ) {
        d[i] = 2*d[i - 1] + 1;
    }
    memset(f, INF, sizeof(f));
    f[1] = 1;
    for (int i = 2; i <= 12; i ++ ) {
        for (int j = 1; j < i; j ++ ) {
            f[i] = min(f[i], 2*f[j] + d[i - j]);
        }
    }
    for (int i = 1; i <= 12; i ++ ) {
        cout << f[i] << endl;
    }

    return 0;
}