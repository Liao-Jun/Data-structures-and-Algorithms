#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,p;
        cin >> n >> p;
        int cnt = 0;
        int c = 1;
        for(int i=p;i<=n;i=p*c){
            int x = 0;
            while(i%2==0){
                i /= 2;
                x++;
            }
            cnt += x;
            c++;
        }
        cout << cnt << endl;
    }

    return 0;
}