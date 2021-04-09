#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;

const int M = 2e5+20;

struct node{
    int x, up_y, down_y, d;
    node (){}
    node (int _x, int _up_y, int _down_y, int _d) : x(_x), up_y(_up_y), down_y(_down_y), d(_d){}
};

bool cmp(const node &a, const node &b) {
    return a.x < b.x;
}

int cover[M];
int length[M];
int yy[M];
node N[M];

void pushup(int l, int r, int rt) {
    if (cover[rt]) length[rt] = yy[r] - yy[l];
    else if (l + 1 == r) length[rt] = 0;
    else length[rt] = length[rt<<1] + length[rt<<1|1];
}

void update(int yl, int yr, int d, int l, int r, int rt) {
    if (yl > r || yr < l) return;
    if (yl <= l && yr >= r) {
        cover[rt] += d;
        pushup(l, r, rt);
        return;
    }
    if (l + 1 == r) return;
    int mid = l + r >> 1;
    if (yl <= mid) update(yl, yr, d, l, mid, rt<<1);
    if (yr > mid) update(yl, yr, d, mid, r, rt<<1|1);
    pushup(l, r, rt);
}

int main() {
    int n;
    scanf("%d", &n);
    int x11, y11, x22, y22;
    int yl, yr, d;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d%d%d%d", &x11, &y11, &x22, &y22);
        N[++ cnt] = node(x11, y22, y11, 1);
        yy[cnt] = y11;
        N[++ cnt] = node(x22, y22, y11, -1);
        yy[cnt] = y22;
    }
    sort(yy + 1, yy + cnt + 1);
    sort(N + 1, N + cnt + 1, cmp);
    int len = unique(yy + 1, yy + cnt + 1) - (yy + 1);
    memset(length, 0, sizeof(length));
    memset(cover, 0, sizeof(cover));
    int sum = 0;
    for (int i = 1; i <= cnt; i ++ ) {
        sum += length[1]*(N[i].x - N[i - 1].x);
        yl = lower_bound(yy + 1, yy + len + 1, N[i].down_y) - yy;
        yr = lower_bound(yy + 1, yy + len + 1,N[i].up_y) - yy;
        d = N[i].d;
        update(yl, yr, d, 1, len, 1);
    }
    cout << sum << endl;

    return 0;
}