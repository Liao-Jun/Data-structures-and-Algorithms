#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    int n;
    char s[2000+5],s1[2000+5];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int cnt = 0;
    int left = 0,right = n-1;
    while(left<=right){
        bool l = true;
        for(int i=0;left+i<right-i;i++){
            if(s[left+i]<s[right-i]){
                break;
            }else if(s[left+i]>s[right-i]){
                l = false;
                break;
            }
        }
        if(l) s1[cnt++] = s[left++];
        else s1[cnt++] = s[right--]; 
    }

    for(int i = 0; i < n; i++){
        if(i % 80 == 0 && i != 0) printf("\n");
        printf("%c", s1[i]);
    }


    return 0;
}

//https://vjudge.net/problem/POJ-3617