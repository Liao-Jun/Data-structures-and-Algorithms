#include <iostream>
#include <cstring>

using namespace std;

const int M = 32010;

int n;
int c[M], num[M];

int lowbit(int x) {
    return x&(-x);
}

void update(int i, int k) {
    while (i <= M) {
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    cin >> n;
    int x, y;
    memset(c, 0, sizeof(c));
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i ++ ) {
        cin >> x >> y;
        x ++;
        num[getsum(x)] ++;
        update(x, 1);
    }
    for (int i = 0; i < n; i ++ ) cout << num[i] << endl;

    return 0;
}