#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int M = 2e5+10;
struct edge{
    int u,v;
    ll cost;
};
int n,m;
int tree;
edge e[M];
int pre[M],Rank[M];

bool cmp(const edge &a, const edge &b){
    return a.cost<b.cost;
}

void init(int n){
    for(int i=0;i<n;i++){
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
    return find_root(x) == find_root(y);
}

ll kruskal(){
    sort(e,e+m,cmp);
    init(n);
    tree = n;
    ll res = 0;
    for(int i=0;i<m;i++){
        edge ed = e[i];
        if(!same(ed.u,ed.v)){
            unite(ed.u,ed.v);
            res += ed.cost;
            tree--;
        }
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[i].u = a;
        e[i].v = b;
        e[i].cost = -c;
    }
    ll res = -kruskal();
    if(tree>1){
        cout << -1 << endl;
    }else{
        cout << res << endl;
    }

    return 0;
}