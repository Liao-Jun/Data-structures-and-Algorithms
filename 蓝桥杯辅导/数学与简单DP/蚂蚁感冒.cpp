#include <iostream>
#include <algorithm>

using namespace std;

int n;
int main() {
    cin >> n;
    int a, b;
    cin >> a;
    int l = 0, r = 0;
    for (int i = 0; i < n - 1; i ++ ) {
        cin >> b;
        if (b > 0 && abs(a) > b) r ++;
        else if (b < 0 && abs(b) > abs(a)) l ++;
    }
    if (a < 0 && r == 0 || a > 0 && l == 0) cout << 1 << endl;
    else cout << l + r + 1 << endl; 

    return 0;
}