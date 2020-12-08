#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 2e5+10;
int a[M];

int main(){
    int n;
    cin >> n;
    int Max = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        Max = max(Max,a[i]);
        sum += 1ll*a[i];
    }
    sum = sum - 1ll*Max;
    sum = sum + 1ll*Max*(n-1);
    cout << sum << endl;

    return 0;
}