#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    set<int> se;
    int x;
    int a = 0, b = 0;
    int Min = INF, Max = 0;
    while (n -- ) {
        while (cin >> x) {
            if(se.count(x) == 0) se.insert(x);
            else b = x;
            Min = min(Min, x);
            Max = max(Max, x);
        }
    }
    for (int i = Min; i <= Max; i ++ ) {
        if (!se.count(i)) a = i;
    }
    if (a == 0) a = Max;
    cout << a << ' ' << b << endl;

    return 0;
}