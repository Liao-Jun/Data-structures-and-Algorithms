//增减序列
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    int p = 0, q = 0;
    ll x, y;
    cin >> x;
    ll sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i ++ ) {
        cin >> y;
        ll t = y - x;
        x = y;
        if (t > 0) sum1 += t;
        else sum2 += -t; 
    }
    cout << max(sum1, sum2) << endl;
    cout << abs(sum1 - sum2) + 1 << endl;

    return 0;
}