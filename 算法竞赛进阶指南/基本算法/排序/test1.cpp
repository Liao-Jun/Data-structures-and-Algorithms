//电影
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

const int maxn = 2e5+10;

int n, m;
unordered_map<int, int> dic;
pair<int, int> d[maxn];

int main() {
    scanf("%d", &n);
    int a;
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &a);
        dic[a] ++;
    }
    scanf("%d", &m);
    int b, c;
    for (int i = 0; i < m; i ++ ) {
        scanf("%d", &b);
        d[i].first = b;
    }
    for (int i = 0; i < m; i ++ ) {
        scanf("%d", &c);
        d[i].second = c;
    }
    int k, Max1 = 0;
    for (int i = 0; i < m; i ++ ) {
        if (dic[d[i].first] > Max1) {
            Max1 = dic[d[i].first];
            k = i;
        }
    }
    int Max2 = 0;
    for (int i = 0; i < m; i ++ ) {
        if (dic[d[i].first] == Max1) {
            if (dic[d[i].second] > Max2) {
                k = i;
                Max2 = dic[d[i].second];
            }
        }
    }
    cout << k + 1 << endl;

    return 0;
}