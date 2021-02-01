#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    double x1,y1,r1,x2,y2,r2;
    while(t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double l;
        l = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        l = sqrt(l);
        double x = max(r1,r2);
        double y = min(r1,r2);
        if(x-y<=l&&l<=y+x){
            cout << "YES\n";
        }else if(x-y==l||l==x+y){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}