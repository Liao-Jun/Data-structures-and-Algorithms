#include <iostream>
#include <algorithm>

using namespace std;

int a[1005], f[1005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    int Max = 0;
    for (int i = 1; i <= n; i ++ ) {
        f[i] = 1;
        for (int j = 1; j < i; j ++ ) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
        Max = max(Max, f[i]);
    }
    cout << Max << endl;

    return 0;
}