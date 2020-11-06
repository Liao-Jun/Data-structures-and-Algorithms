#include <iostream>
using namespace std;

bool Judge(int &W){
    int W1,D1,W2,D2;
    cin >> W1 >> D1 >> W2 >> D2;
    bool a=true,b=true; 
    if(W1==0) a=Judge(W1);
    if(W2==0) b=Judge(W2);
    W = W1+W2;
    if(a&&b&&W1*D1==W2*D2){
        return true;
    }else{
        return false;
    }
}

int main(){
    int t, w;
    cin >> t;
    while(t--){
        if(Judge(w)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        if(t) cout << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-839