#include <iostream>
#include <algorithm>
using namespace std;

bool isp(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int n;
int a[20];
int vis[20];

void dfs(int cnt){
    if(cnt==n&&isp(a[0]+a[n-1])){
        cout << a[0];
        for(int i=1;i<n;i++){
            cout << ' ' << a[i];
        }
        cout << endl;
    }else
    for(int i=2;i<=n;i++){
        if(!vis[i]&&isp(i+a[cnt-1])){
            a[cnt] = i;
            vis[i] = 1;
            dfs(cnt+1);
            vis[i] = 0;
        }
    }
}

int main(){
    int flag = 0;
    while(cin >> n){
        if(flag){
            cout << endl;
        }
        flag++;
        fill(vis,vis+20,0);
        a[0] = 1;
        cout << "Case " << flag << ':' << endl;
        dfs(1);
    }

    return 0;
}

//https://vjudge.net/problem/UVA-524