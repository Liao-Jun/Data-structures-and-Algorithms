//编辑器
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;

stack<int> a, b;
int sum[maxn], f[maxn];

int main() {
    int t;
    cin >> t;
    char c;
    int x;
    memset(f, -INF, sizeof(f));
    while (t -- ) {
        cin >> c;
        if (c == 'I') {
            cin >> x;
            a.push(x);
            sum[a.size()] = sum[a.size() - 1] + x;
            f[a.size()] = max(sum[a.size()], f[a.size() - 1]);
        }else if (c == 'D') {
            if (!a.empty()) a.pop();
        }else if (c == 'L') {
            if (!a.empty()) {
                int x = a.top();
                a.pop();
                b.push(x);
            }
        }else if (c == 'R') {
            if (b.empty()) continue;
            a.push(b.top());
            b.pop();
            sum[a.size()] = sum[a.size() - 1] + a.top();
            f[a.size()] = max(sum[a.size()], f[a.size() - 1]);
        }else if (c == 'Q') {
            cin >> x;
            cout << f[x] << endl;
        }
    }

    return 0;
}