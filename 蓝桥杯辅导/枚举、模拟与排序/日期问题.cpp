#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dic[][2] = {{31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

struct node{
    int y, m, d;
};

bool cmp(const node &a, const node &b) {
    if (a.y == b.y) {
        if (a.m == b.m) return a.d < b.d;
        return a.m < b.m;
    }
    return a.y < b.y;
}

int get_year(int Year) {
    if (Year%4 != 0) return 0;
    if (Year%4 == 0 && Year%400 == 0) return 1;
    if (Year%4 == 0 && Year%100 == 0) return 0;
    return 1;
}

int main() {
    string s;
    cin >> s;
    int a, b, c;
    a = (s[0] - '0')*10 + s[1] - '0';
    b = (s[3] - '0')*10 + s[4] - '0';
    c = (s[6] - '0')*10 + s[7] - '0';
    node N[4];
    int cnt = 0;
    for (int i = 0; i < 3; i ++ ) {
        int A = 2000 + a;
        int B = b, C = c;
        if (i == 1) A = 2000 + c, B = a, C = b;
        if (i == 2) A = 2000 + c, B = b, C = a;
        if (a == b && b == c && i != 0) continue;
        if (a == b && i > 1) continue;
        if (A >= 2060) A -= 100;
        int f = get_year(A);
        if (B > 12 || B <= 0) continue;
        if (dic[B - 1][f] < C || C <= 0) continue;
        N[cnt].y = A, N[cnt].m = B, N[cnt ++].d = C;
    }
    sort(N, N + cnt, cmp);
    for (int i = 0; i < cnt; i ++ ) {
        cout << N[i].y << '-';
        if (N[i].m < 10) cout << '0';
        cout << N[i].m << '-';
        if (N[i].d < 10) cout << '0';
        cout << N[i].d << endl;
    }

    return 0;
}