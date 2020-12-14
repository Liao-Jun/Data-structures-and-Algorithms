#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 5e3+10;
struct edge{
    int to,cost;
};
vector<edge> ed[M];
int dist[M];
int dist1[M];
int V;
typedef pair<int,int> P;

void Dijkstra(){
    priority_queue<P,vector<P>,greater<P>> q;
    dist[0] = 0;
    q.push(P(0,0));
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        int d = p.first;
        if(dist1[v]<d) continue;
        for(int i=0;i<ed[v].size();i++){
            edge e = ed[v][i];
            int d1 = d + e.cost;
            if(dist[e.to]>d1){
                swap(dist[e.to],d1);
                q.push(P(dist[e.to],e.to));
            }
            if(dist1[e.to]>d1&&dist[e.to]<d1){
                dist1[e.to] = d1;
                q.push(P(dist1[e.to],e.to));
            }
        }
    }
}

int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    memset(dist,INF,sizeof(dist));
    memset(dist1,INF,sizeof(dist1));
    edge e;
    int from;
    int V = n;
    for(int i=0;i<r;i++){
        cin >> from >> e.to >> e.cost;
        from--;
        e.to--;
        ed[from].push_back(e);
        swap(e.to,from);
        ed[from].push_back(e);
    }
    Dijkstra();
    cout << dist1[V-1] << endl;
    return 0;
}

//https://vjudge.net/problem/POJ-3255