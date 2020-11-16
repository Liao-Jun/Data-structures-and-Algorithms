#include <iostream>
using namespace std;

int main(){
    bool x = true;
    cout << x << "&1 " << (x&1) << endl;
    cout << x << "&0 " << (x&0) << endl;
    cout << x << "|1 " << (x|1) << endl;
    cout << x << "|0 " << (x|0) << endl;
    cout << x << "^1 " << (x^1) << endl;
    cout << x << "^0 " << (x^0) << endl;
    x = false;
    cout << x << "&1 " << (x&1) << endl;
    cout << x << "&0 " << (x&0) << endl;
    cout << x << "|1 " << (x|1) << endl;
    cout << x << "|0 " << (x|0) << endl;
    cout << x << "^1 " << (x^1) << endl;
    cout << x << "^0 " << (x^0) << endl;
    return 0;
}