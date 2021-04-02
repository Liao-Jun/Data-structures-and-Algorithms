#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int dic[][2] = {{31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};
int x, y, X, Y, x11, x22, x33, y11, y22, y33;

int get_year(int y111) {
    if (y111%4 != 0) return 0;
    if (y111%4 == 0 && y111%400 == 0) return 1;
    if (y111%4 == 0 && y111%100 == 0) return 0;
    return 1;
}

bool judge(int y111, int a, int b) {
    if (a >= 13) return false;
    int f = get_year(y111);
    if (b > dic[a - 1][f]) return false;
    int t = y111*10000 + a*100 + b;
    if (t < X || t > Y) return false;
    return true;
}

int main() {
    string s1, s2;
    int cnt = 0;
    cin >> s1 >> s2;
    stringstream stream;
    stream << s1;
    stream >> x;
    stream.clear();
    stream << s2;
    stream >> y;
    X = x, Y = y;
    x11 = x/10000;
    x %= 10000;
    x22 = x/100;
    x33 = x%100;
    y11 = y/10000;
    y %= 10000;
    y22 = y/100;
    y33 = y%100;
    for (int i = x11; i <= y11; i ++ ) {
        int a = i%10*10 + i%100/10;
        int b = i/100%10*10 + i/100/10;
        if (judge(i, a, b)) cnt ++;
    }
    cout << cnt << endl;

    return 0;
}