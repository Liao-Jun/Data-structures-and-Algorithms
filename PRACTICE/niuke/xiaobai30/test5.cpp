#include <iostream>
#include <string>
using namespace std;

const int M = 2e5+10;

int main(){
    string a,b;
    cin >> a;
    cin >> b;
    int s[M];
    int cnt = 0;
    for(int i=a.length()-1,j=b.length()-1;i>=0||j>=0;i--,j--){
        if(i>=0&&j>=0){
            s[cnt++] = ((a[i]-'0')+(b[j]-'0'))%10;
        }else if(i>=0||j>=0){
            int x = i>j?a[i]-'0':b[j]-'0';
            s[cnt++] = x;
        }
    }
    int x[M];
    int j = 0;
    int cnta = 0;
    for(int i=cnt-1;i>=0;i--){
        x[j++] = s[i];
        if(s[i]==0){
            cnta++;
        }
    }
    int flag = 0;
    for(int i=0;i<j;i++){
        if(x[i]!=0){
            flag=1;
        }
        if(flag){
            cout << x[i];
        }
    }
    if(cnta==j){
        cout << 0;
    }
    cout << endl;

    return 0;
}