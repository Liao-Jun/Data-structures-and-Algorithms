#include <iostream>
#include <algorithm>
#include <stdio.h>

int h1, m1, s1, h2, m2, s2;
int t;

int getTime(){
    int d = 0;
    scanf("%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    int T1 = h1*60*60 + m1*60 + s1;
    int T2 = (h2 + d*24)*60*60 + m2*60 + s2;
    return T2 - T1;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        int x1 = getTime();
        int x2 = getTime();
        int x = (x1 + x2)/2;
        printf("%02d:%02d:%02d\n", x/3600, x/60%60, x%60);
    }

    return 0;
}