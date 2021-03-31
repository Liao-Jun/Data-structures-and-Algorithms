#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s1,s2;
int a[105];

int main() {
    memset(a, 0, sizeof(a));
    cin >> s1 >> s2;
    int cnt = 0;
    for (int i = 0; i < s1.length() - 1; i ++ ) {
        if (s1[i] == s2[i] && a[i]%2 == 1) {
            a[i] ++;
            a[i + 1] ++;
        }else if (s1[i] != s2[i] && a[i]%2 == 0) {
            a[i] ++;
            a[i + 1] ++;
        }
        cnt += a[i];
    }
    cout << cnt/2 << endl;

    return 0;
}