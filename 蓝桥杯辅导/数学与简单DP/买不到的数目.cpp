#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 1e6+5;

int n, m;
bool f[M];

int main() {
    cin >> n >> m;
    int Min = min(n, m), Max = n*m;
    memset(f, false, sizeof(f));
    f[0] = true;
    int cnt = 0;
    for (int i = Min; i < Max; i ++ ) {
        if (f[i - Min]) f[i] = true;
        else if (i >= max(n, m) && f[i - max(n, m)]) f[i] = true;
        else cnt = i;
    }
    cout << cnt << endl;

    return 0;
}