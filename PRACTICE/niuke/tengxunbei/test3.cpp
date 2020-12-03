#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int a = 0, b = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='y'||s[i]=='Y'){
                a++;
            }else if(s[i]=='n'||s[i]=='N'){
                b++;
            }
        }
        int c = (s.length())/2;
        if(a>=c){
            cout << "pmznb" << endl;
        }else if(b>=c){
            cout << "lyrnb" << endl;
        }else{
            cout << "wsdd" << endl;
        }
    }

    return 0;
}