#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt = 0;
int used[11], a[11];

bool check(int x, int y) {
    if (x != 6 && x != 1) {
        if (a[x -1] > y) return false;
    }
    if (x >= 6) {
        if (y < a[x - 5]) return false;
    }
    return true;
}

void dfs(int x) {
    if (x > 10) {
        cnt ++;
        return;
    }
    for (int i = 1; i <= 10; i ++ ) {
        if (used[i] == 0 && check(x,i)) {
            used[i] = 1;
            a[x] = i;
            dfs(x + 1);
            used[i] = 0;
        }
    }
}

int main() {
    // dfs(1);
    // cout << cnt << endl;
    cout << 42 << endl;

    return 0;
}