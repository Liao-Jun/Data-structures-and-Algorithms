#include <iostream>
using namespace std;

int main(){
    typedef int state[9];
    state a[10];
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            a[i][j] = i*j;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}