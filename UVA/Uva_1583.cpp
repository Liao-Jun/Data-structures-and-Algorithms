#include <iostream>
using namespace std;

int Sum(int x){
    int sum=0;
    while(x>9){
        sum += x%10;
        x=x/10;
    }
    sum += x;
    return sum;
}

int P(int x){
    int sum=0;
    while(x>9){
        sum ++;
        x=x/10;
    }
    sum ++;
    return sum;
}
int main(){
    int t;
    int x;
    cin >> t;
    for(int i=0;i<t;i++){
        int result = 0;
        cin >> x;
        for(int i=x-P(x)*9;i<x;i++){
            if(i+Sum(i)==x){
                result = i;
                break;
            }
        }
        cout << result << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1583