#include <iostream>

using namespace std;

bool getyear(int y) {
    if (y%4 == 0 && y%400 == 0) return true;
    if (y%4 == 0 && y%100 == 0) return false;
    if (y%4 ==0) return true;
    return false;
}

int main() {
    int sum = 0;
    for (int i = 1901; i <= 2000; i ++ ) {
        if (getyear(i)) sum += 366;
        else sum += 365;
    }
    cout << sum/7 << endl;

    return 0;
}