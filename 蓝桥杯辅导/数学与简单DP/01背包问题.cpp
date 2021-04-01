#include <iostream>
#include <algorithm>

using namespace std;

int N, V;
int v[1005], w[1005];
int f[1005][1005];

int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i ++ ) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= N; i ++ ) {
        for (int j = 1; j <= V; j ++ ) {
            if (j < v[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]);
        }
    }
    cout << f[N][V] << endl;

    return 0;
}