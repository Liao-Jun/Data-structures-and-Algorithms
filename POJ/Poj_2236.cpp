#include <iostream>
#include <cstring>
using namespace std;

const int M = 1001;
int pre[M+5];
int vis[M+5];
pair<int,int> x[M+5];

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
    int n,d;
    cin >> n >> d;
    for(int i=0;i<M;i++){
        pre[i] = i;
    }
    memset(vis,0,M+5);
    for(int i=1;i<=n;i++){
        cin >> x[i].first >> x[i].second;
    }
    char flag;
    int p,q;
    while(~scanf("%c",&flag)){
        if(flag=='O'){
            cin >> p;
            vis[p] = 1;
            for(int i=0;i<=n;i++){
                if(vis[i]&&i!=p){
                    // cout << '?' << i << endl;//debug
                    // cout << '!' << x[i].first << x[i].second << '!' << x[p].first << x[p].second << '!' << endl;//debug
                    if(((x[i].first-x[p].first)*(x[i].first-x[p].first)+(x[i].second-x[p].second)*(x[i].second-x[p].second))<=d*d){
                        int ri = find_root(i);
                        join(p,ri);
                        // cout << p << ' ' << ri << '?' << endl;//debug
                    }
                }
            }
        }else if(flag=='S'){
            cin >> p >> q;
            int rp = find_root(p);
            int rq = find_root(q);
            // cout << rp << rq << '@' << endl;//debug
            if(rp==rq){
                cout << "SUCCESS\n";
            }else{
                cout << "FAIL\n";
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/POJ-2236