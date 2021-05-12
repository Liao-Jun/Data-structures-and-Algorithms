//递归实现组合型枚举
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void dfs(int k) {
    if (v.size() > m || v.size() + n - k + 1 < m) return;
    if (k == n + 1) {
        for (auto l : v) {
            cout << l << ' ';
        }
        cout << endl;
        return;
    }
    v.push_back(k);
    dfs(k + 1);
    v.pop_back();
    dfs(k + 1);
}

int main() {
    cin >> n >> m;
    dfs(1);

    return 0;
}