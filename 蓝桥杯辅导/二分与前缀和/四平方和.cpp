#include <iostream>
#include <algorithm>

using namespace std;

const int M = 5e6 + 10;
struct node{
    int c,d,sum;
};

bool cmp(const node &a, const node &b) {
    if (a.sum == b.sum && a.c == b.c) return a.d < b.d;
    else if (a.sum == b.sum) return a.c < b.c;
    else return a.sum < b.sum;
}

int n, a, b, c, d;
node N[M];

int main() {
    cin >> n;
    int cnt = 0;
    for (c = 0; c*c <= n; c ++ ) {
        for (d = c; c*c + d*d <= n; d ++ ) {
            N[cnt].c = c;
            N[cnt].d = d;
            N[cnt ++ ].sum = c*c + d*d;
        }
    }
    sort(N, N + cnt, cmp);
    for (a = 0; a*a <= n; a ++ ) {
        for (b = a; a*a + b*b <= n; b ++ ) {
            int t = n - a*a - b*b;
            int l = 0, r = cnt;
            while (l < r) {
                int mid = l + r >> 1;
                if (N[mid].sum >= t) r = mid;
                else l = mid + 1;
            }
            if (N[l].sum == t) {
                cout << a << ' ' << b << ' ' << N[l].c << ' ' << N[l].d << endl;
                return 0;
            }
        }
    }

    return 0;
}