#include <iostream>
#include <algorithm>
using namespace std;

const int M = 5E5+5;
struct Node
{
    int l,r,val;
};

Node y[M];
int m = 0;

void dfs(int i, int cnt){
    if(y[i].l!=0){
        dfs(y[i].l,cnt+1);
        dfs(y[i].r,cnt+1);
        if(cnt<m){
            y[i].val = max(y[y[i].l].val,y[y[i].r].val);
        }else{
            y[i].val = min(y[y[i].l].val,y[y[i].r].val);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        y[i].l = a;
        y[i].r = b;
        if(!(!a&&!b)){
            m++;
        }
    }
    int v;
    for(int i=1;i<=n;i++){
        cin >> v;
        y[i].val = v;
    }
    m = (m+1)/2;
    dfs(1,0);
    cout << y[1].val << endl;

    return 0;
}