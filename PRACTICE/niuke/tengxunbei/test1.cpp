#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        int sum = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a;
            sum = max(sum,a);
        }
        cout << sum << endl;
    }

    return 0;
}