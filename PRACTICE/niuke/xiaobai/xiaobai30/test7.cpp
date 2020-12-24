#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int M = 2e5+10;
int a[M],b[M];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n,greater<int>());
    sort(b,b+m,greater<int>());
    int cnt = 0;
    for(int i=0,j=0;i<m;i++){
        if(b[i]<a[j]){
            j++;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}