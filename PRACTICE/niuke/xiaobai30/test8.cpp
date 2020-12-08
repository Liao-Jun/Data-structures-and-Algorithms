#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 2e5+10;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[M];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    priority_queue<int> q;
    int cnt = 0;
    for(int i=0;i<k&&i<n;i++){
        q.push(a[i]);
        cnt++;
    }
    int x,y;
    while(m--){
        cin >> x;
        if(x==2){
            if(k>cnt){
                cout << -1 << endl;
            }else{
                cout << q.top() << endl;
            }
        }else{
            cin >> y;
            q.push(y);
            cnt++;
            if(cnt>k){
                q.pop();
                cnt--;
            }
        }
    }

    return 0;
}