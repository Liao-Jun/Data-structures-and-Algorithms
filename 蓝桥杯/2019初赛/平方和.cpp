#include <iostream>
#include <set>

using namespace std;

using ll = long long;

set<int> se;

bool judge(int x) {
    while (x > 9) {
        if (se.count(x%10) != 0) return true;
        x /= 10;
    }
    if (se.count(x) != 0) return true;
    return false;
}

int main() {
    // ll sum1 = 0, sum2 = 0;
    // se.insert(2);
    // se.insert(0);
    // se.insert(1);
    // se.insert(9);
    // for (int i = 1; i <= 2019; i ++ ) {
    //     if (judge(i)) sum1 += 1ll*i, sum2 += 1ll*i*i;
    // }
    // cout << sum1 << ' ' << sum2 << endl;
    cout << 2658417853 << endl;

    return 0;
}