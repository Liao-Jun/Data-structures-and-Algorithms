#include <iostream>
using namespace std;

int main(){
    int a, b;
    int flag = 0;
    int k = 0;
    int x[30000];
    int y[30000];
    while(scanf("%d%d",&a,&b)!=EOF){
        int sum = 0;
        int result1 = 0,result2 = 0;
        if(flag!=0){
            cout << endl;
        }
        flag++;
        cout << a << '/' << b << " = ";
        cout << a/b;
        a = a%b;
        y[0] = a;
        cout << '.';
        if(a==0){
            cout << "(0)" << endl;
            cout << "   1 = number of digits in repeating cycle" << endl;
            continue;
        }
        while(a!=0){
            a = a*10;
            int c = a/b;
            a = a%b;
            if(a==0){
                k = 1;
            }
            x[sum++] = c;
            y[sum] = a;
            for(int i=0;i<=sum-1;i++){
                if(y[i]==y[sum-1]&&i!=sum-1){
                    a = 0;
                    result1 = sum-1;
                    result2 = i;
                    break;
                }
            }
        }
        if(k==1){
            for(int i=0;i<sum;i++){
                if(i==50){
                    cout << "...)";
                    break;
                }
                cout << x[i];
            }
            cout << "(0)" << endl;
            cout << "   1 = number of digits in repeating cycle" << endl;
            k = 0;
            continue;
        }
        for(int i = 0;i<sum;i++){
            if(i==50){
                cout << "...)";
                break;
            }
            if(i==result2){
                cout << '(';
            }else if(i==sum-1){
                cout << ')';
                continue;
            }
            cout << x[i];
        }
        cout << endl;
        cout << "   " << result1-result2 << " = number of digits in repeating cycle" << endl;
    }
    cout << endl;
    return 0;
}

//https://vjudge.net/problem/UVA-202