#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(b+a-1<7*a){
        cout << -1 << endl;
    }else{
        cout << 7*a << endl;
    }

    return 0;
}