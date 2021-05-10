#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

bool judge(ll x) {
    set<int> se;
    int cnt = 1;
    while (x > 9) {
        if (cnt >= 10) return false;
        se.insert(x%10);
        x /= 10;
        cnt ++;
    }
    se.insert(x);
    if (se.size() == 10) return true;
    return false;
}

int main() {
    // ll a;
    // for (ll i = 100000; ; i --) {
    //     if (judge(i*i)) {
    //         cout << i*i << endl;
    //         return 0;
    //     }
    // }
    cout << 9814072356 << endl;

    return 0;
}