#include <iostream>
#include <string>
using namespace std;

string s;
int t;

int Judge(int a, int b, int n){
    for(int j=a,k=b,l=0;l<n;j++,j=j%n,k++,k=k%n){
        if(s[j]>s[k]){
            return b;
        }else if(s[j]<s[k]){
            return a;
        }
    }
    return a;
}

int main(){
    cin >> t;
    s.clear();
    for(int i=0;i<t;i++){
        cin >> s;
        int flag = 0;
        int n = s.length();
        for(int j=1;j<n;j++){
            flag = Judge(flag,j,n);
        }
        for(int j=flag,l=0;l<n;l++,j++,j=j%n){
            cout << s[j];
        }
        cout << endl;
        s.clear();
    }
}

//https://vjudge.net/problem/UVA-1584