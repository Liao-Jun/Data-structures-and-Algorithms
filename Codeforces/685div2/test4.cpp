#include <iostream>
using namespace std;

typedef long long ll;

void Judge(int d, int k){
    int x=0,y=0,cnt=0;
    while(1ll*x*x+1ll*y*y<=1ll*d*d){
        if(x==y){
            x += k;
        }else if(x>y){
            y = x;
        }else if(x<y){
            x = y;
        }
        // cout << x << ' ' << y << endl;
        cnt ++;
    }
    if(cnt%2) cout << "Utkarsh" << endl;
    else cout << "Ashish" << endl;
}

int main(){
    int t,d,k;
    cin >> t;
    while(t--){
        cin >> d >> k;
        Judge(d,k);
    }

    return 0;
}