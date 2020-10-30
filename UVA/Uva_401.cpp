#include <iostream>
#include <string>
using namespace std;

bool isPolindrome(string s){
    int m = s.length();
    for(int i=0,j=m-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}

char Reverse(char x){
    switch(x){
        case 'A':return 'A';
        case 'E':return '3';
        case 'H':return 'H';
        case 'I':return 'I';
        case 'J':return 'L';
        case 'L':return 'J';
        case 'M':return 'M';
        case 'O':return 'O';
        case 'S':return '2';
        case 'T':return 'T';
        case 'U':return 'U';
        case 'V':return 'V';
        case 'W':return 'W';
        case 'X':return 'X';
        case 'Y':return 'Y';
        case 'Z':return '5';
        case '1':return '1';
        case '2':return 'S';
        case '3':return 'E';
        case '5':return 'Z';
        case '8':return '8';
        default:return 'B';
    }
}

bool isMirrored(string s){
    int m = s.length();
    for(int i=0,j=m-1;i<=j;i++,j--){
        if(Reverse(s[i])=='B'){
            return false;
        }else if(Reverse(s[i])!=s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    while(cin>>s){
        if(!isPolindrome(s)&&!isMirrored(s)){
            cout << s << " -- is not a palindrome.\n" << endl;
        }else if(isPolindrome(s)&&!isMirrored(s)){
            cout << s << " -- is a regular palindrome.\n" << endl;
        }else if(!isPolindrome(s)&&isMirrored(s)){
            cout << s << " -- is a mirrored string.\n" << endl;
        }else{
            cout << s << " -- is a mirrored palindrome.\n" << endl;
        }
        s.clear();
    }

    return 0;
}

//https://vjudge.net/problem/UVA-401#author=Luke