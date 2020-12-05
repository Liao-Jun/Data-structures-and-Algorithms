#include <iostream>
using namespace std;
int main() {
    int t;    cin >> t;
    while(t--) {
        int n;    cin>>n;
        if(n == 1)    cout << 1 << endl;
        else if(n == 2)    cout<< "2 2" <<endl;
        else if(n % 2 == 1) {
            for (int i = 2; i < n; i++)
                cout << i << " ";
            for (int i = 2; i < n; i++) {
                if (i != n-1)    cout << i << " ";
                else    cout << i <<endl;
            }
        }
        else if(n % 2 == 0) {
            for (int i = 2; i < n; i++)
                cout << i << " ";
            for (int i = n-1; i > 1; i--) {
                if (i != 2)    cout << i << " ";
                else    cout << i <<endl;
            }
        }
    }
    return 0;
}
