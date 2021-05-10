//起床困难综合症
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;

using ll = long long;

int n, m, t;
string op;

int main() {
    cin >> n >> m;
    bitset<32> zero, one;
    zero.reset();
    one.set();
    for (int i = 0; i < n; i ++ ) {
        cin >> op >> t;
        if (op == "AND") zero &= t, one &= t;
        else if (op == "OR") zero |= t, one |= t;
        else if (op == "XOR") zero ^= t, one ^= t;
    }
    int res = 0;
    for (int i = 0; i < 31; i ++ ) {
        if (zero[i] == 1) res += (1 << i);
        else if (one[i] == 1 && m > (1 << i)) res += (1 << i); 
    }
    cout << res << endl;

    return 0;
}