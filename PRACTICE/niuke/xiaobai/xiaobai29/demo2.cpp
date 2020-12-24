#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 0, b = (1<<20)-1;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(x==1){
            a &= y;
            b &= y;
        }else if(x==2){
            a |= y;
            b |= y;
        }else if(x==3){
            a ^= y;
            b ^= y;
        }
    }
    int And = (1<<20)-1, Or = 0, Xor = 0;
    for(int i=0;i<20;i++){
        if((a>>i)&1){
            if((b>>i)&1){
                Or += (1<<i);
            }else if(!((b>>i)&1)){
                Xor += (1<<i);
            }
        }else if(!((a>>i)&1)){
            if(!((b>>i)&1)){
                And -= (1<<i);
            }
        }
    }
    cout << 3 << endl;
    cout << 1 << ' ' << And << endl;
    cout << 2 << ' ' << Or << endl;
    cout << 3 << ' ' << Xor << endl;

    return 0;
}