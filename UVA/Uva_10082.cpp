#include<iostream>
using namespace std;

char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(){
    int i,c;
    while((c=getchar())!=EOF){
        for(i=0;s[i]&&s[i]!=c;i++)
        	if(s[i])	putchar(s[i-1]);
        	else	putchar(c);
    }
    return 0;
}

//https://vjudge.net/problem/UVA-10082#author=0