#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e6+10;

int a[maxn], d[maxn];
int A, B, C, m, n;
int lat[maxn], rat[maxn], lbt[maxn], rbt[maxn], lct[maxn], rct[maxn], h[maxn];

int get(int x, int y, int z){
    if (x > A || y > B || z > C) return  0;
    return ((x - 1)*B + (y - 1))*C + (z - 1) + 1;
}

bool judge(int mid){
    for (int i = 0; i <= n; i ++ ) d[i] = 0;
    for (int i = 1; i <= mid; i ++ ) {
        d[get(lat[i], lbt[i], lct[i])] += h[i];
        d[get(lat[i], rbt[i] + 1, lct[i])] -= h[i];
        d[get(rat[i] + 1, lbt[i], lct[i])] -= h[i];
        d[get(rat[i] + 1, rbt[i] + 1, lct[i])] += h[i];
        d[get(lat[i], lbt[i], rct[i] + 1)] -= h[i];
        d[get(lat[i], rbt[i] + 1, rct[i] + 1)] += h[i];
        d[get(rat[i] + 1, lbt[i], rct[i] + 1)] += h[i];
        d[get(rat[i] + 1, rbt[i] + 1, rct[i] + 1)] -= h[i];
    }
    // for (int i = 1; i <= A; i ++ )
    //     for (int j = 1; j <= B; j ++ )
    //         for (int k = 1; k <= C; k ++ ) {
    //             d[get(i, j, k)] += d[get(i, j, k - 1)] + d[get(i - 1, j, k)] + d[get(i, j - 1, k)] - d[get(i - 1, j - 1, k)] - d[get(i - 1, j, k - 1)] - d[get(i, j - 1, k - 1)] + d[get(i - 1, j - 1, k - 1)];
    //             if(d[get(i, j, k)] > a[get(i, j, k)]) return true;
    //         }
        for (int i=1; i<=A; i++)
        for (int j=1; j<=B; j++)
            for (int k=1; k<C; k++)
                d[get(i,j,k+1)] += d[get(i,j,k)];

    for (int i=1; i<=A; i++)
        for (int k=1; k<=C; k++)
            for (int j=1; j<B; j++)
                d[get(i,j+1,k)] += d[get(i,j,k)];

    for (int j=1; j<=B; j++)
        for (int k=1; k<=C; k++)
            for (int i=1; i<A; i++)
                d[get(i+1,j,k)] += d[get(i,j,k)];
    for (int i = 1; i <= n; i ++ ) {
        if (d[i] > a[i]) return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d%d", &A, &B, &C, &m);
    n = A*B*C;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i ++ ) scanf("%d%d%d%d%d%d%d", &lat[i], &rat[i], &lbt[i], &rbt[i], &lct[i], &rct[i], &h[i]);
    int l = 1, r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;

    return 0;
}