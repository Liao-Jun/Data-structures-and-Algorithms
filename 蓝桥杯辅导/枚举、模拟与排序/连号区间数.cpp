#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int p[10005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> p[i];
    }
    int cnt = 0;
    int Max11, Min11;
    for (int i = 0; i < n; i ++) {
        Max11 = 0, Min11 = INF;
        for (int j = i; j < n; j ++ ) {
            Max11 = max(Max11, p[j]);
            Min11 = min(Min11, p[j]);
            if (Max11 - Min11 == j - i) cnt ++;
        }
    }
    cout << cnt << endl;

    return 0;
}