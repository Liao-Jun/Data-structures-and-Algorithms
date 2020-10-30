#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string s;
int t;

float Judge(char a){
    if(a=='C'){
        return 12.01;
    }else if(a=='H'){
        return 1.008;
    }else if(a=='O'){
        return 16.00;
    }else if(a=='N'){
        return 14.01;
    }
    return 0;
}

int main(){
    s.clear();
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        int x = 0;
        int n = s.length();
        float sum = 0;
        float y = 0;
        for(int j=0;j<n;j++){
            if(s[j]>='A'&&s[j]<'Z'){
                if(!(s[j-1]>'A'&&s[j-1]<'Z')){
                    sum += y*x;
                    x = 0;
                    y = 0;
                }
                if(j==n-1||s[j+1]>='A'&&s[j+1]<'Z'){
                    sum += Judge(s[j]);
                }else{

                    y = Judge(s[j]);
                }
            }else{
                x *=10;
                x += (s[j]-'0');
                if(j==n-1){
                    sum += x*y;
                    x = 0;
                    y = 0;
                }
            }
        }

        printf("%.3f\n",sum);
        sum = 0;
        s.clear();
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1586#author=0