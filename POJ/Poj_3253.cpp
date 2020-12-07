#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    int n;
    priority_queue<int,vector<int>,greater<int>> q;
    int x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        q.push(x);
    }
    ll sum = 0;
    while(!q.empty()){
        int a = q.top();
        q.pop();
        if(q.empty()){
            break;
        }
        int b = q.top();
        q.pop();
        sum += 1ll*a+1ll*b;
        q.push(a+b);
    }
    cout << sum << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-3253