#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a =  0;
    int b = pow(2, 19);
    for (int t = b; t >= 1; ) {
        a += t;
        t /= 2;
    }
    cout << a << '/' << b << endl;

    return 0;
}