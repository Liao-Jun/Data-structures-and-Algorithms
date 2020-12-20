#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string s;
char dic[8] = {'N','o','w','C','o','d','e','r'};

bool judge(int a,int b){
    int used[8] = {0,0,0,0,0,0,0,0};
    for(int i=a;i<=b;i++){
        for(int j=0;j<8;j++){
            if(s[i]==dic[j]&&used[j]!=1){
                used[j] = 1;
                continue;
            }
        }
    }
    for(int i=0;i<8;i++){
        if(used[i]!=1) return false;
    }
    return true;
}

int main(){
    cin >> s;
    int sum = 0;
    for(int i=0;i<s.length();i++){
        if(i+7>=s.length()){
            break;
        }
        if(judge(i,i+7)) sum++;
    }
    cout << sum << endl;
    
    return 0;
}