#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a,b;
    int sum = 0;
    if(n%2==0){
        a = n/2;
        b = n/2;
        for(int i=a;i>=0;i-=2){
            for(int j=i;j>=0;j-=2){
                if(i==0&&j==0) sum += 1;
                else if(i==0||j==0) sum += 4;
                else if(i==j) sum += 4;
                else sum += 8;
            }
        }
    }else{
        a = n/2+1;
        b = n/2;
        for(int i=a;i>=0;i-=2){
            for(int j=b;j>=0;j-=2){
                if(j==0||i==0) sum += 4;
                else sum += 8;
            }
        }
    }
    cout << sum << endl;

    return 0;
}