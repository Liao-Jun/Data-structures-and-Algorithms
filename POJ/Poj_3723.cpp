#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 5e5+10;
const int S = 2e5+10;
struct edge{
    int u,v;
    int cost;
};
edge e[M];
int pre[S],Rank[S];
int n,m,r;
int tree;

bool cmp(const edge &a, const edge &b){
    return a.cost<b.cost;
}

void init(int x){
    for(int i=0;i<x;i++){
        pre[i] = i;
        Rank[i] = 0;
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

ll Kruskal(){
    sort(e,e+r,cmp);
    init(n+m);
    ll res = 0;
    for(int i=0;i<r;i++){
        edge ed = e[i];
        if(!same(ed.u,ed.v)){
            unite(ed.u,ed.v);
            res += ed.cost;
        }
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&r);
        for(int i=0;i<r;i++){
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].cost);
            e[i].v += n;
            e[i].cost = -e[i].cost;
        }
        ll res = 10000*(n+m)+Kruskal();
        printf("%lld\n",res);
    }

    return 0;
}

//https://vjudge.net/problem/POJ-3723