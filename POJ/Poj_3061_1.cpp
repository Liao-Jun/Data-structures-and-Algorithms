//二分搜索
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 1e5+10;
typedef long long ll;
int n,s;
int a[M];
ll sum[M];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(i==0) sum[0] = 1ll*a[0];
            else sum[i] = sum[i-1]+1ll*a[i];
        }
        if(sum[n-1]<s){
            cout << 0 << endl;
            continue;
        }
        int res = n+1;
        for(int i=0;sum[i]+s<=sum[n-1];i++){
            int t = lower_bound(sum+i,sum+n,sum[i]+s)-sum;
            res = min(res,t-i);
        }
        cout << res << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3061