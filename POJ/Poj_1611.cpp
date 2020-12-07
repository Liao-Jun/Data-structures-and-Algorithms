#include <iostream>
#include <cstring>
using namespace std;

const int M = 3e5+5;
int pre[M];

int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
}

void join(int x, int y){
    int rx = find_root(x);
    int ry = find_root(y);
    if(rx!=ry){
        pre[rx] = ry;
    }
}

int main(){
    int n,m,k;
    while(cin>>n>>m&&!(n==0&&m==0)){
        for(int i=0;i<M;i++){
            pre[i] = i;
        }
        for(int i=0;i<m;i++){
            cin >> k;
            int a,b;
            for(int j=0;j<k;j++){
                cin >> a;
                if(j==0){
                    b=a;
                    continue;
                }
                join(a,b);
            }
        }
        int root = find_root(0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(find_root(i)==root){
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1611