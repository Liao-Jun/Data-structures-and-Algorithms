#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    string s;
    int step;
    node (string _s = "@", int _step = 0) {
        s = _s;
        step = _step;
    }
};

node n1, n2;
int cnt = 0;
map<string, int> m;

void bfs() {
    m[n1.s] = 1;
    queue<node> q;
    q.push(n1);
    while (!q.empty()) {
        node N;
        N = q.front();
        q.pop();
        m[N.s] = 1;
        if (N.s == n2.s) {
            n2.step = N.step;
            break;
        }
        int f;
        for (f = 0; f < 9; f ++ ) {
            if (N.s[f] == '0') break;
        }
        for (int i = f - 2; i <= f + 2; i ++ ){
            int j = (i + 9) % 9;
            if (j == f) continue;
            string s = N.s;
            swap(s[j], s[f]);
            if (m[s] == 0) {
                m[s] = 1;
                node n3;
                n3.s = s;
                n3.step = N.step + 1;
                q.push(n3);
            }
        }
    }
}

int main() {
    n1.s = "012345678";
    n2.s = "087654321";
    n1.step = n2.step = 0;
    // bfs();
    n2.step = 20;
    cout << n2.step << endl;

    return 0;
}