#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    double x11 = 2.3, y11 = 2.5;
    double x22 = 6.4, y22 = 3.1;
    double x33 = 5.1, y33 = 7.2;
    double S = (x22 - x11)*(y33 - y11);
    double S1 = (x33 - x11)*(y33 - y11)/2;
    double S2 = (x22 - x33)*(y33 - y22)/2;
    double S3 = (x22 - x11)*(y22 - y11)/2;
    cout << S - S1 - S2 - S3 << endl;

    return 0;
}