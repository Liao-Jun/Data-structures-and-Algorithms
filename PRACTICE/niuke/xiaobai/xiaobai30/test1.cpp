#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 2e5+10;
int n, m;
struct edge{
    int u,v;
    int cost;
};
edge e[M];
int pre[M],Rank[M];
int tree;

bool cmp(const edge &a, const edge &b){
    return a.cost < b.cost;
}

void init(int x){
    for(int i=0;i<x;i++){
        pre[i]=i;
        Rank[i]=0;
    }
}

int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
}

void unite(int x, int y){
    int rx = find_root(x);
    int ry = find_root(y);
    if(rx==ry) return;
    if(Rank[rx]<Rank[ry]){
        pre[rx] = ry;
    }else{
        pre[ry] = rx;
        if(Rank[rx]==Rank[ry]){
            Rank[rx]++;
        }
    }
}

bool same(int x, int y){
    return find_root(x)==find_root(y);
}

int kruskal(){
    sort(e,e+m,cmp);
    init(n);
    int res = 0;
    tree = n;
    for(int i=0;i<m;i++){
        edge ed = e[i];
        if(!same(ed.u,ed.v)){
            unite(ed.u,ed.v);
            tree--;
            if(ed.cost==1){
                res ++;
            }
        }
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> e[i].u >> e[i].v >> e[i].cost;
    }
    int res = kruskal();
    if(tree>1){
        cout << -1 << endl;
    }else{
        cout << res << endl;
    }

    return 0;
}