#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int M = 1e3+10;
int a[M],b[M];
int n;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string s;
        cin >> s;
        for(int i=0;i<n;i++){
            a[i] = s[i]-'0';
        }
        cin >> s;
        for(int i=0;i<n;i++){
            b[i] = s[i]-'0';
        }
        int r = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) continue;
            a[i]>b[i]?r++:c++;
        }
        if(c==r){
            cout << "EQUAL\n";
        }else if(r>c){
            cout << "RED\n";
        }else cout << "BLUE\n";
    }

    return 0;
}