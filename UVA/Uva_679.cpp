#include <iostream>
using namespace std;

int main(){
    int l;
    while(scanf("%d",&l)&&l!=-1){
        int D,I;
        while(l--&&scanf("%d%d",&D,&I)==2){
            long long int k = 1;
            for(int i=1;i<=D-1;i++){
                if(I%2==1){
                    k = k*2;
                    I = (I+1)/2;
                }else{
                    k = k*2+1;
                    I = I/2;
                }
            }
            cout << k << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-679