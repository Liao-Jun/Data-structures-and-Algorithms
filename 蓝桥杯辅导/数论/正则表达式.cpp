#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string s;
int i;

int dfs() {
    int cnt1 = 0;
    int cnt = 0;
    while (i < s.length()) {
        if (s[i] == '(') {
            i ++;
            cnt += dfs();
        }else if (s[i] == ')') {
            i ++;
            break;
        }else if (s[i] == '|') {
            i ++;
            cnt1 = max(cnt1, cnt);
            cnt = 0;
        }else {
            cnt ++;
            i ++;
        }
    }
    return max(cnt1, cnt);
}

int main() {
    cin >> s;
    cout << dfs() << endl;

    return 0;
}