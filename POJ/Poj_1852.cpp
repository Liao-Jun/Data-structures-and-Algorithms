#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1e6+5;
int cm,n;
int a[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> cm >> n;
        int amin,amax;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        amin = min(a[0],cm-a[0]);
        amax = max(a[0],cm-a[0]);
        for(int i=1;i<n;i++){
            amin = max(amin,min(a[i],cm-a[i]));
            amax = max(amax,max(a[i],cm-a[i]));
        }
        cout << amin << ' ' << amax << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1852