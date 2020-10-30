#include <iostream>
#include <string>
using namespace std;

bool Judge(string s, string t){
    int n = t.length();
    int sum = 0;
    for(int i=0;i<n;i++){
        if(t[i]==s[sum])sum++;
    }
    if(sum == s.length()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s,t;
    while(cin >> s >> t){
        if(Judge(s,t)){
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-10340