#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e6+10;

int x[maxn];

int main() {
    // memset(x, 0, sizeof(x));
    // for (int i = 1; i*i < maxn; i ++ ) {
    //     x[i*i] = 1;
    // }
    // int cnt = 0;
    // int re;
    // for (int i = 1; i < maxn; i ++ ) {
    //     cnt = 0;
    //     for (int j = 1; j < i; j ++ ) {
    //         if (x[j] == 1 && x[i - j] == 1) cnt ++;
    //     }
    //     if (cnt  == 24) {
    //         re = i;
    //         break;
    //     }
    // }
    // cout << re << endl;
    cout << 160225 << endl;

    return 0;
}