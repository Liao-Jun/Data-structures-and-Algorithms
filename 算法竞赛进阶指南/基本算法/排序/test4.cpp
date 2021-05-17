//动态中位数
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int p, n, m, x;

int main() {
    cin >> p;
    while (p -- ) {
        cin >> n >> m;
        cout << n << ' ' << (m + 1)/2 << endl;
        priority_queue<int, vector<int>, less<int>> p1;
        priority_queue<int, vector<int>, greater<int>> p2;
        int cnt = 0;
        for (int i = 1; i <= m; i ++ ) {
            cin >> x;
            if (i == 1 || x < p1.top()) p1.push(x);
            else p2.push(x);
            while (p2.size() > p1.size()) {
                p1.push(p2.top());
                p2.pop();
            }
            while (p1.size() > p2.size() + 1) {
                p2.push(p1.top());
                p1.pop();
            }
            if (i&1) {
                cout << p1.top();
                cnt ++;
                if (cnt%10 == 0 || i == m) cout << endl;
                else cout << ' ';
            }
        }
    }

    return 0;
}