#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
const int M = 2E5+5;
int t,n,k,k1;
int a[M];
ll sum;

void Sum(int i,int j){
    sum += a[j-n+k];
    i = i+(k-1);
    j = j-n-1+k;
    if(i<j){
        Sum(i,j);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k1;
        sum = 0;
        k = (n+1)/2;
        for(int i=0;i<n*k1;i++){
            cin >> a[i];
        }
        if(n>2){
            Sum(0,n*k1-1);
        }else if(n==2){
            for(int i=0;i<n*k1;i++){
                if((i+1)%n==k){
                    sum += a[i];
                }
            }
        }else if(n==1){
            for(int i=0;i<n*k1;i++){
                sum += a[i];
            }
        }
        cout << sum << endl;
    }

    return 0;
}