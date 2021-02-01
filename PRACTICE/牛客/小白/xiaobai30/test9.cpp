#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int M = 3e3+10;
int a[M];
ll x[M][M];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum = a[i];
        x[i][i] = sum;
        for(int j=i+1;j<n;j++){
            sum ^= a[j];
            x[i][j] = sum;
        }
    }
    int s;
    while(m--){
        cin >> s;
        int t = INF;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(x[i][j]>s){
                    t = min(t,j-i+1);
                }
            }
        }
        cout << t << endl;
    }
    

    return 0;
}