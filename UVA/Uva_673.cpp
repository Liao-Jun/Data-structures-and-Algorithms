#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

int main(){
    int n;
    cin >> n;
    getchar();
    while(n--){
        while(!s.empty()){
            s.pop();
        }
        char c;
        while((c=getchar())!='\n'){
            if(c=='['||c=='('){
                s.push(c);
            }else if(c==']'||c==')'){
                if(s.empty()){
                    s.push(c);
                }else{
                    if(c==']'){
                        if(s.top()=='['){
                            s.pop();
                        }
                    }else if(c==')'){
                        if(s.top()=='('){
                            s.pop();
                        }
                    }
                }
            }
        }
        if(s.empty()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-673