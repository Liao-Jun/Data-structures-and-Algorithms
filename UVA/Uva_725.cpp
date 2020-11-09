#include <iostream>
#include <set>
using namespace std;

set<int> dic;

int main(){
    int n;
    int cnt = 0;
    while(cin >> n&&n!=0){
        bool result = false;
        if(cnt++){
            cout << endl;
        }
        for(int i=1234;i<=100000/n;i++){
            dic.clear();
            if(i*n>=100000){
                break;
            }
            int a = i;
            int b = i*n;
            for(int j=0;j<5;j++){
                dic.insert(a%10);a/=10;
                dic.insert(b%10);b/=10;
            }
            if(dic.size()==10){
                printf("%05d / %05d = %d\n",i*n,i,n);
                result = true;
            }
        }
        if(!result){
            printf("There are no solutions for %d.\n",n);
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-725