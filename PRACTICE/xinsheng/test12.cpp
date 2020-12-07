#include <iostream>
#include <algorithm>
using namespace std;

const double pi = 3.1415926535;

int main(){
    int t;
    cin >> t;
    double a,b,r,h;
    while(t--){
        cin >> a >> b >> r >> h;
        double sum = 0;
        double x;
        x = abs(a-b);
        if(abs(a-b)>180){
            x = 360.0-abs(a-b);
        }
        sum = (x/360.0)*2*pi*r;
        sum *=sum;
        sum += h*h;
        printf("%.2lf\n",sum);
    }

    return 0;
}