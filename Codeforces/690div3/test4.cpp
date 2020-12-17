#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    int a[3000+10];
    while(t--){
        cin >> n;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        int k = n;
        while(k>=1){
            if(k==1){
                cout << n-1 << endl;
                break;
            }
            if(sum%k==0){
                int s = sum/k;
                int s1 = 0;
                int flag = 1;
                for(int i=0;i<n;i++){
                    s1 += a[i];
                    if(s1==s) s1=0;
                    else if(s1>s){
                        flag = -1;
                        break;
                    }
                    else if(i==n-1&&s1<s) flag = -1;
                }
                if(flag==1){
                    cout << n-k << endl;
                    break;
                }
            }
            k--;
        }
    }

    return 0;
}