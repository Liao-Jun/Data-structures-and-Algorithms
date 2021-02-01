#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        int p;
        cin >> p >> s;
        if((s[s.length()-1]-'0')%2){
            cout << p-1 << endl;
        }else{
            cout << 1 << endl;
        }

    }

    return 0;
}