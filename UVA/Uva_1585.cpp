#include <iostream>
#include <string>
using namespace std;

string s;
int t;

int main(){
    s.clear();
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        int n = s.length();
        int sum=0;
        int sum1=0;
        for(int j=0;j<n;j++){
            if(j==0){
                if(s[j]=='O'){
                    sum1 = 1;
                    sum = 1;
                }else{
                    sum1 = 0;
                }
                continue;
            }
            if(s[j]=='O'){
                if(s[j-1]=='O'){
                    sum1++;
                    sum += sum1;
                }else{
                    sum1=0;
                    sum1++;
                    sum += sum1;
                }
            }
        }
        cout << sum << endl;
        s.clear();
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1585#author=0