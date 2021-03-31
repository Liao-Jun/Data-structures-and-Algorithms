#include <iostream>
#include <cstring>

using namespace std;

int n, cnt = 0;
int num[10];
bool used[10];

int change(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; i ++ ) {
        res = res*10 + num[i];
    }
    return res;
}

void dfs(int k) {
    if (k == 9) {
        for (int i = 0; i < 7; i ++ ) {
            for (int j = i + 1; j < 8; j ++ ) {
                int a = change(0, i);
                int b = change(i + 1, j);
                int c = change(j + 1, 8);
                if (a*c + b == n*c) {
                    cnt ++;
                }
            }
        }
        return;
    }
    for (int i = 1; i <= 9; i ++ ) {
        if(!used[i]) {
            num[k] = i;
            used[i] = true;
            dfs(k + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    memset(used, false, sizeof(used));
    dfs(0);
    cout << cnt << endl;

    return 0;
}