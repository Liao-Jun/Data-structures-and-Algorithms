#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        list<int> l;
        list<int>::iterator it;
        it = l.begin();
        for(int j=1;j<=n;j++){
            l.insert(it,j);
            it++;
        }
        for(int i=0;i<m;i++){
            string s;
            getline(cin,s);
            if(s[0]=='1'){
                
            }
        }
    }

    return 0;
}