//给树染色
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node{
    int p, v, size;
    double avg;
};

node A[1010];
int n, root;

int find() {
    int r;
    double avg = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (i != root && A[i].avg > avg) {
            avg = A[i].avg;
            r = i;
        }
    }
    return r;
}

int main() {
    cin >> n >> root;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        cin >> A[i].v;
        A[i].avg = A[i].v;
        A[i].size = 1;
        cnt += A[i].v;
    }
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        A[b].p = a;
    }
    for (int i = 1; i < n; i ++ ) {
        int p = find();
        int f = A[p].p;
        cnt += A[p].v*A[f].size;
        A[p].avg = -1;
        for (int j = 1; j <= n; j ++ ) {
            if (A[j].p == p) {
                A[j].p = f;
            }
        }
        A[f].v += A[p].v;
        A[f].size += A[p].size;
        A[f].avg = (double)A[f].v/A[f].size;
    }
    cout << cnt << endl;

    return 0;
}