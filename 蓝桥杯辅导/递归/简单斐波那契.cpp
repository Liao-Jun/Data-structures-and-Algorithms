#include <iostream>
#include <cstring>

using namespace std;

int a[50];

int main() {
    int n;
    memset(a, 0, sizeof(a) );
    cin >> n;
    a[1] = 1;
    a[2] = 1;
    for (int i = 0; i < n; i ++ ) {
        if (i < 3) cout << a[i] << ' ';
        else {
            a[i] = a[i-1] + a[i-2];
            cout << a[i] << ' ';
        }
    }
 
    return 0;
}