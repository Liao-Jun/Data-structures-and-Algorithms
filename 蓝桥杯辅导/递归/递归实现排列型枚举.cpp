#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a[10];
    int n;
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
    }while(next_permutation(a,a+n));

    return 0;
}