#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[2000+5],b[2000+5];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int x=0;
    for(int i=1;i<n;i++){
        b[x] = a[i]-a[i-1];
        x++;
    }
    x--;
    sort(b,b+x+1);
    int sum = 0;
    for(int i=0;i<=x+1-k;i++){
        sum += b[i];
    }
    cout << sum+k << endl;

    return 0;
}