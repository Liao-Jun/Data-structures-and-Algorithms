// Problem:
// 贝茜受雇在农场主约翰的N个谷仓(2 <= N <= 1000)之间建立一个廉价的互联网网络。
// FJ已经做了一些调查，发现了M (1 <= M <= 20,000)对谷仓之间可能的连接路径。每
// 个可能的连接路由都有一个相关的成本C (1 <= C <= 100,000)。农民约翰想要在连接
// 网络上花费最少的钱;他甚至都不想付钱给贝茜。意识到农场主约翰不会给她钱，贝茜决
// 定做最坏的工作。她必须决定一组连接安装,所以(我)这些连接的总成本是尽可能大,
// (2)所有的谷仓都连接在一起(这样就可以达到任何谷仓从其他仓库通过安装连接的路
// 径),和(iii),这样没有周期之间的连接(农民约翰很容易能够检测)。条件(ii)和(iii)确
// 保最后的连接集看起来像一个“树”。
// Input:
// *第1行:两个空格分隔的整数:N和M*线2 . .M+1:每行包含三个以空格分隔的整数A、B和C，它
// 们描述了成本为C的仓库A和仓库B之间的连接路由。
// Output:
// *第1行:单个整数，包含连接所有仓库的最昂贵树的价格。如果不可能连接所有的谷仓，输出-1。
// Sample Input:
// 5 8
// 1 2 3
// 1 3 7
// 2 3 10
// 2 4 4
// 2 5 8
// 3 4 6
// 3 5 2
// 4 5 17
// Sample Output:
// 42
// Hint
// 输出详细信息：
// 最昂贵的树的成本为17 + 8 + 10 + 7 =42。它使用以下连接：4到5、2到5、2到3和1到3。


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
int tree;//判断森林是否可以转化为树
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
            tree--;//判断森林是否可以变成树
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
        e[i].cost = -c;//最大生成树或者最小生成树，最大生成树取反
    }
    ll res = -kruskal();
    if(tree>1){
        cout << -1 << endl;
    }else{
        cout << res << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-2377