//递归实现排列型枚举
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n;
    int a[15];
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        a[i] = i + 1;
    }
    do{
        cout << a[0];
        for (int i = 1; i < n; i ++ ) {
            cout << ' ' << a[i];
        }
        cout << endl;
    }while(next_permutation(a, a + n));

    return 0;
}