#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = n;
    while (n >= 3) {
        int t = n/3;
        n = n - 2*t;
        sum += t;
    }
    cout << sum << endl;

    return 0;
}