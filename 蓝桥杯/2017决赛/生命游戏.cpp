#include <iostream>
#include <cstring>

using namespace std;

char s[][50] = {"................................................",
               "................................................",
               "................................................",
               "..............................X.................",
               "............................X.X.................",
               "..................XX......XX............XX......",
               ".................X...X....XX............XX......",
               "......XX........X.....X...XX....................",
               "......XX........X...X.XX....X.X.................",
               "................X.....X.......X.................",
               ".................X...X..........................",
               "..................XX............................",
               "................................................",
               "................................................",
               "................................................",
               "................................................"};
int s_num[18][50];
int dic[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

int get_num(int x, int y) {
    int cnt = 0;
    // if (x == 1) cout << x << ' ' << y << endl;//debug
    for (int i = 0; i < 8; i ++ ) {
        int x11 = x + dic[i][0];
        int y11 = y + dic[i][1];
        // if (x == 1) cout << x11 << ' '<< y11 << '&';//debug
        if (x11 >= 0 && x11 < 16 && y11 >= 0 && y11 < 48) {
            if (s[x11][y11] == 'X'){
                cnt ++;
                // if(x == 1) cout << x11 << '*' << y11 << endl;//debug
            }
        }
    }
    return cnt;
}

int main() {
    // // freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
    // freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    // memset(s_num, 0, sizeof(s_num));
    // int cnt = 0;
    // for (int i = 0; i < 16; i ++ ) {
    //     for (int j = 0; j < 48; j ++ ) {
    //         cout << s[i][j];
    //         s_num[i][j] = get_num(i, j);
    //         if (s[i][j] == 'X') cnt ++;
    //     }
    //     cout << endl;
    // }
    // cout << cnt << endl;
    // cout << "------------------0--------------------------" << endl;
    // // for (int i = 0; i < 11; i ++ ) {
    // //     for (int j = 0; j < 38; j ++ ) {
    // //         cout << s_num[i][j];
    // //     }
    // //     cout << endl;
    // // }

    // int t = 100;
    // while (t --) {
    //     cnt = 0;
    //     for (int i = 0; i < 16; i ++ ) {
    //         for (int j = 0; j < 48; j ++ ) {
    //             if (s[i][j] == 'X' && s_num[i][j] < 2) s[i][j] = '.';
    //             else if (s[i][j] == 'X' && s_num[i][j] > 3) s[i][j] = '.';
    //             else if (s[i][j] == '.' && s_num[i][j] == 3) s[i][j] = 'X';
    //         }
    //     }
    //     for (int i = 0; i < 16; i ++ ) {
    //         for (int j = 0; j < 48; j ++ ) {
    //             cout << s[i][j];
    //             s_num[i][j] = get_num(i, j);
    //             if (s[i][j] == 'X') cnt ++;
    //         }
    //         cout << endl;
    //     }
    //     cout << cnt << endl;
    //     cout << "----------------" << 100 - t << "-------------------" << endl;
    // }
    int n = 1e9;
    long long sum = 48;
    sum += n/30*5;
    cout << sum << endl;

    return 0;
}