#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    while(cin >> s&&s[0]!='.'){
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}