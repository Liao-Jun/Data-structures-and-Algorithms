#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int b[5][5];
string s[5];

int main() {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < 4; i ++ ) {
        cin >> s[i];
        for (int j = 0; j < 4; j ++ ) {
            if (s[i][j] == '+') {
                for (int k = 0; k < 4; k ++ ) {
                        b[i][k] ++;
                        b[k][j] ++;
                }
                b[i][j] --;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 4; j ++ ) {
            if (b[i][j] % 2 == 1) cnt ++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 4; j ++ ) {
            if (b[i][j] % 2 == 1) cout << i+1 << ' ' << j+1 << endl; 
        }
    }

    return 0;
}