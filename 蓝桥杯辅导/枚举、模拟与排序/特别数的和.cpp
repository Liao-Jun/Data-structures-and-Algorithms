#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        set<int> s;
        int t = i;
        while (t > 9) {
            s.insert(t%10);
            t /= 10;
        }
        s.insert(t);
        if (s.count(2) || s.count(0) || s.count(1) || s.count(9)) cnt += i;
    }
    cout << cnt << endl;

    return 0;
}