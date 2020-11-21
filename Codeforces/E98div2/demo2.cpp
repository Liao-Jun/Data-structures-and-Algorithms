#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

string s;


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        stack<char> s1, s2;
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1.push('(');
            }else if(s[i]==')'){
                if(!s1.empty()){
                    cnt++;
                    s1.pop();
                }
            }else if(s[i]=='['){
                s2.push('[');
            }else if(s[i]==']'){
                if(!s2.empty()){
                    cnt++;
                    s2.pop();
                }
            }
        }
        cout << cnt << endl;
    }


    return 0;
}