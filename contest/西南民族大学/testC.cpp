#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
struct node{
    int v,cost;
    node(int _v,int _cost):v(_v),cost(_cost){};
};

struct Node{
    int point,dist;
    Node(int _point, int _dist):point(_point),dist(_dist){};
    bool operator<(const Node &a)const{
        return dist>a.dist;
    }
};

const int M = 2e4+10;
int V;
ll dist[M];
int used[M];
vector<node> e[M];

void Dijkstra(){
    priority_queue<Node> q;
    dist[1] = 0;
    q.push(Node(1,0));
    while(!q.empty()){
        Node temp = q.top();
        q.pop();
        int u = temp.point;
        if(used[u]==1){
            continue;
        }
        used[u] = 1;
        for(int i=0;i<e[u].size();i++){
            int v = e[u][i].v;
            int cost = e[u][i].cost;
            if(dist[u]+1ll*cost<dist[v]&&used[v]==0){
                dist[v] = 1ll*dist[u]+1ll*cost;
                q.push(Node(v,dist[v]));
            }
        }
    }

}
bool cmp(pair<int,ll> &a, pair<int,ll> &b){
    if(a.second!=b.second){
        return a.second>b.second;
    }else{
        return a.first<b.first;
    }
}

int main(){
    int t,n;
    cin >> t >> n;
    V = n;
    memset(dist,INF,sizeof(dist));
    memset(used,0,sizeof(used));
    int x,y,z;
    for(int i=1;i<=n;i++){
        cin >> x >> y >> z;
        e[x+1].push_back(node(y+1,z));
    }
    Dijkstra();
    pair<int,ll> p[M];
    for(int i=2;i<=V+1;i++){
        p[i-2].first = i;
        p[i-2].second = dist[i];
    }
    sort(p,p+V,cmp);
    cout << p[0].second << ' ' << p[0].first-1 << endl;

    return 0;
}