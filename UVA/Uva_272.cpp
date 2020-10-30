#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    char s;
    int flag=0;
    while(scanf("%c",&s)!=EOF){
        if(flag==0&&s=='"'){
            printf("``");
            flag++;
        }else if(flag==1&&s=='"'){
            printf("''");
            flag--;
        }else{
            printf("%c",s);
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-272#author=acmparand