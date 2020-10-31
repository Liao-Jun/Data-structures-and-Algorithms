#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        list<char> l;
        list<char>::iterator it;
        it = l.begin();
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                it = l.begin();
            }else if(s[i]==']'){
                it = l.end();
            }else{
                it = l.insert(it, s[i]);
                it++;
            }
        }
        for(auto i : l){
            cout << i;
        }
        cout << endl;
        l.clear();
    }

    return 0;
}

//https://vjudge.net/problem/UVA-11988