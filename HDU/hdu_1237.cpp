#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main(){
    double n;
    char x;
    stack<double> p;
    while(1){
        double sum = 0;
        cin >> n;
        x = getchar();
        if(n==0&&x=='\n'){
            break;
        }
        p.push(n);
        while(cin >> x >> n){
            if(x=='+'){
                p.push(n);
            }else if(x=='-'){
                p.push(-n);
            }else if(x=='*'){
                n=n*(p.top());
                p.pop();
                p.push(n);
            }else if(x=='/'){
                n=p.top()/n;
                p.pop();
                p.push(n);
            }
            if(getchar()=='\n'){
                break;
            }
        }
        while(!p.empty()){
            sum +=p.top();
            p.pop();
        }
        printf("%.2lf\n",sum);
        //cout << endl;
    }

    return 0;
}