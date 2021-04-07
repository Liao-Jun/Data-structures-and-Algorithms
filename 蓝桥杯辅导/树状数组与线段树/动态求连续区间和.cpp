#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e5+10;

struct node{
    int l, r;
    int sum;
};

int a[M];
node tree[M*4];

void push_up(int u) {
    tree[u].sum = tree[u<<1].sum + tree[u<<1|1].sum;
}

void build(int u, int l, int r) {
    if (l == r) tree[u] = {l, r, a[l]};
    else {
        tree[u] = {l,r};
        int mid = l + r >> 1;
        build(u<<1, l, mid);
        build(u<<1|1,mid + 1, r);
        push_up(u);
    }
}

int quary(int u, int l, int r) {
    if (l <= tree[u].l && tree[u].r <= r) return tree[u].sum;
    else {
        int mid = tree[u].l + tree[u].r >> 1;
        int sum = 0;
        if (l <= mid) sum += quary(u<<1, l, r);
        if (mid + 1 <= r) sum += quary(u<<1|1, l, r);
        return sum;
    }
}

void modify(int u, int x, int v) {
    if (tree[u].l == tree[u].r) tree[u].sum += v;
    else {
        int mid = tree[u].l + tree[u].r >> 1;
        if (x <= mid) modify(u<<1, x, v);
        else modify(u<<1|1, x, v);
        push_up(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    build(1, 1, n);
    while (m --){
        int f, x, y;
        cin >> f >> x >> y;
        if (f == 0) cout << quary(1, x, y) << endl;
        else if (f == 1) {
            modify(1, x, y);
        }
    }

    return 0;
}