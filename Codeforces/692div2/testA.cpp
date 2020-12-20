#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n;
string s;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') sum++;
            else break; 
        }
        if(sum>n/2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}