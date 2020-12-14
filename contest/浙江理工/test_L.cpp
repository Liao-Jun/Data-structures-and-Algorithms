#include <iostream>
#include <string>
using namespace std;

const int M = 1e5+10;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    int flag = 1;
    for(int i=0;i<s.length();i++){
        if(s[i]){
            if(s[i]=='0'){
                flag = -1;
            }
            while(s[i]==s[i+1]){
                cnt++;
                i++;
            }
        }
        cnt++;
        break;
    }
    if(flag==1&&cnt%2==1){
        cout << "clysdd\n";
    }else if(flag==1){
        cout << "clynb\n";
    }else if(flag==-1&&cnt%2==1){
        cout << "clynb\n";
    }else{
        cout << "clysdd\n";
    }

    return 0;
}