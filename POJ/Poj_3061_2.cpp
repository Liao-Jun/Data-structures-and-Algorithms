//尺取法
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1e5+10;
typedef long long ll;
int n,k;
int a[M];

int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int res = n+1;
        int s = 0,t = 0;
        ll sum = 0;
        for(;;){
            while(t<n&&sum<k){
                sum += 1ll*a[t++];
            }
            if(sum<k) break;
            res = min(res, t-s);
            sum -= a[s++];
        }
        if(res>n) cout << 0 << endl;
        else cout << res << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3061