#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+10;
const int maxn1 = 1e6+10;

int n;
int a[maxn];
int s[maxn1];

int find_root(int x) {
    if (x != s[x]) {
        s[x] = find_root(s[x]);
    }
    return s[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= maxn1; i ++ ) {
        s[i] = i;
    }
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        int root = find_root(a[i]);
        a[i] = root;
        s[root] = find_root(root + 1);
        cout << a[i] << ' ';
    }


    return 0;
}