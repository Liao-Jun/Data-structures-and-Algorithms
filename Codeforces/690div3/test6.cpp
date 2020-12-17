#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 2e5+10;
const int mod = 1e9+7;

int a[M];

ll c(int cnt, int m){
    ll sum = 1;
    for(int i=cnt;i>=cnt-m+1;i--){
        sum = (1ll*sum*i)%mod;
    }
    for(int i=2;i<=m;i++){
        sum = (1ll*sum/i)%mod;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    int n,m,k;
    while(t--){
        cin >> n >> m >> k;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        ll sum = 0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j+1<n&&a[j+1]-a[i]<=k){
                j++;
            }
            int cnt = j-i;
            if(cnt>=m-1){
                sum = (sum+1ll*c(cnt,m))%mod;
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}