#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll x, y;
    cin >> x >> y;
    ll r = 0;
    if (y >= -x && y >= x) {
        ll t = 4*y*y - 2*y;
        if (x <= 0) t += abs(x + y);
        else t += y + abs(x);
        r = t;
    }else if (y >= -x && y <= x) {
        ll t = 4*x*x;
        if (y <= 0) t += x + abs(y);
        else t += abs(x - y);
        r = t;
    }else if (y <= -x && y <= (x + 1)) {
        ll t = 4*y*y - 2*y;
        if (x >= 0) t +=  (abs(y) - abs(x));
        else t += abs(y) + abs(x);
        r = t;
    }else if (y <= -x && y >= (x + 1)) {
        ll t = 4*x*x + 2*x;
        if (y >= 0) t -= (abs(x) - abs(y));
        else t -= (abs(x) + abs(y));
        r = t;
    }
    cout << r << endl;

    return 0;
}