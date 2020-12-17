#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    string s;
    while(t--){
        cin >> n >> s;
        if(s.substr(0,4)=="2020") cout << "YES\n";
        else if(s.substr(s.length()-4,4)=="2020") cout << "YES\n";
        else if(s[0]=='2'&&s.substr(s.length()-3,3)=="020") cout << "YES\n";
        else if(s.substr(0,2)=="20"&&s.substr(s.length()-2,2)=="20") cout << "YES\n";
        else if(s.substr(0,3)=="202"&&s[s.length()-1]=='0') cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}