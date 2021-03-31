#include <iostream>

using namespace std;

int main() {
    double n;
    cin >> n;
    double l = -10000.0, r = 10000.0;
    while (r - l >= 0.0000001) {
        double mid = (l + r)/2;
        if (mid*mid*mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf\n",l);

    return 0;
}