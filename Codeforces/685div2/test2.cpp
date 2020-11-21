#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t,n,q;
string s;
int l,r;

bool Judge(){
    for(int i=0;i<n;i++){
        if(i<l-1){
            if(s[i]==s[l-1]){
                return true;
            }
        }
        if(i>r-1){
            if(s[i]==s[r-1]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> t;
    while(t--){
        s.clear();
        cin >> n >> q;
        cin >> s;
        for(int i=0;i<q;i++){
            cin >> l >> r;
            if(!Judge()) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}