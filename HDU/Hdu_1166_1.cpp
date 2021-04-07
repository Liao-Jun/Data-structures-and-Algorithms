#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int M = 5e4+10;

int a[M],c[M];
int n;

int lowbit(int x) {
    return x&(-x);
}

void update(int i, int k) {
    while (i <= n) {
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
    int t;
    cin >> t;
    int cnt = 0;
    while (t --) {
        cout << "Case " << ++cnt << ':' << endl;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n;i ++ ) {
            cin >> a[i];
            update(i, a[i]);
        }
        string s;
        int a, b;
        while(cin >> s && s != "End") {
            if (s == "Query") {
                cin >> a >> b;
                cout << getsum(b) - getsum(a - 1) << endl;
            } else if (s == "Add") {
                cin >> a >> b;
                update(a, b);
            }else if(s == "Sub") {
                cin >> a >> b;
                update(a, -b);
            }
        }
    }

    return 0;
}