#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1e5+10;
typedef long long ll;
int t0[M];
int x0[M];

int main(){
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&t0[i],&x0[i]);
        }
        int cnt = 0;
        ll sum = 0;
        int st = t0[0];
        int flag = x0[0];
        int tflag = x0[0];
        int res = 0;
        int f = -1;
        while(st<=t0[n-1]){
            if(st==t0[cnt]&&sum==flag) flag = x0[cnt]; 
            if(st==t0[cnt]){
                tflag = x0[cnt];
                cnt++;
            }
            if(sum<flag) sum++;
            else if(sum>flag) sum--;
            if(sum==tflag) res++;
            st++;
            cout << sum << ' ' << flag << ' ' << tflag << endl;
            if(st==t0[n-1]&&sum!=tflag){
                if(sum < flag&&sum<tflag&&tflag<flag){
                    f = 1;
                }else if(sum>flag&&sum>tflag&&tflag>flag){
                    f = 1;
                }
            }
        }
        cout << res << endl;
        if(f==1) res++;
        cout << '?' << res << '?' << endl;
    }

    return 0;
}