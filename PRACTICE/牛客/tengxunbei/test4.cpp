#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    ll a[100+5];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int x,b,c;
    while(m--){
        cin >> x >> b >> c;
        int sum = 0;
        if(x==1){
            for(int i=b-1;i<c;i++){
                a[i] = (1ll*a[i])*(1ll*251)%(1ll*996)*(1ll*404)*(1ll*123);
            }
        }else if(x==2){
            map<ll,int> d;
            for(int i=b-1;i<c;i++){
                if(d[a[i]]>=1){
                    d[a[i]]++;
                    sum = max(sum,d[a[i]]);
                }else{
                    d[a[i]]=1;
                    sum = max(sum,d[a[i]]);
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}