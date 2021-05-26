#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> m;
char dic[2] = {'O', 'L'};

int check(string s) {
    if (m.find(s) != m.end()) return m[s];
    if (s.length() < 3) {
        m[s] = 0;
        return 0;
    }
    if (s.find("L*L") != -1 || s.find("*OL") != -1 || s.find("LO*") != -1) {
        m[s] = 1;
        return 1;
    }
    if (s.find('*') == -1 && s.find("LOL") == -1) {
        m[s] = 0;
        return 0;
    }
    bool flag = false;
    for (int i = 0; i < s.length(); i ++ ) {
        if (s[i] == '*') {
            for (int j = 0; j < 2; j ++ ) {
                s[i] = dic[j];
                if (s.find("L*L") != -1 || s.find("*OL") != -1 || s.find("LO*") != -1) {
                    s[i] = '*';
                    continue;
                }
                int f = check(s);
                s[i] = '*';
                if (f == 1) {
                    continue;
                }else if (f == -1) {
                    m[s] = 1;
                    return 1;
                }else if (f == 0) {
                    flag = true;
                }
            }
        }
    }
    if (flag) {
        m[s] = 0;
        return 0;
    }
    m[s] = -1;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n -- ) {
        string s;
        cin >> s;
        cout << check(s) << endl;
    }

    return 0;
}