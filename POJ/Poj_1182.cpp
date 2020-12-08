#include <iostream>
using namespace std;

const int M = 5e5*3+10;
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

bool Jugde(int x, int y){
    return find_root(x)==find_root(y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k,d,x,y;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;i++){
        pre[i] = i;
    }
    int cnt = 0;
    while(k--){
        scanf("%d%d%d",&d,&x,&y);
        if(x<=0||x>n||y<=0||y>n){
            // cout << x << ' ' << y << endl;//debug
            cnt++;
            continue;
        }
        if(d==1){
            if(Jugde(x,y+n)||Jugde(x,y+2*n)||Jugde(x+n,y)||Jugde(x+n,y+2*n)||Jugde(x+2*n,y)||Jugde(x+2*n,y+n)){
                // cout << x << ' ' << y << endl;//debug
                cnt++;
                continue;
            }else{
                join(x,y);
                join(x+2*n,y+2*n);
                join(x+n,y+n);
            }
        }else if(d==2){
            if(x==y){
                // cout << x << ' ' << y << endl;//debug
                cnt++;
                continue;
            }
            if(Jugde(x,y)||Jugde(x,y+2*n)||Jugde(x+n,y)||Jugde(x+n,y+n)||Jugde(x+2*n,y+n)||Jugde(x+2*n,y+2*n)){
                // cout << x << ' ' << y << endl;//debug
                cnt++;
                continue;
            }else{
                join(x,y+n);
                join(x+n,y+2*n);
                join(x+2*n,y);
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}

//https://vjudge.net/problem/POJ-1182