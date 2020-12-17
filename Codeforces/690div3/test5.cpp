#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 2e5+10;

int main(){
    int t;
    scanf("%d",&t);
    int n;
    int a[M];
    while(t--){
        scanf("%d",&n);
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int j=1;
        ll sum = 0;
        for(int i=0;i<n;i++){
            while(j+1<n&&a[j+1]-a[i]<=2){
                j++;
            }
            int cnt = j-i;
            if(cnt>=2){
                sum += 1ll*cnt*(cnt-1)/2;
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}