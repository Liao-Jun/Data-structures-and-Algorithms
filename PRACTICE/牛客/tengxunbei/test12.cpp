#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    double n,l,m;
    cin >> n >> l >> m;
    double sum = 0;
    for(int i=1;i<=n;i++){
        sum += (l/(2*n));
    }
    printf("%.4lf\n",sum);

    return 0;
}