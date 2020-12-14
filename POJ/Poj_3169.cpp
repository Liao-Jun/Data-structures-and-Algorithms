#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;
vector<P> ed[1000+5];
int dist[1000+5];
int used[1000+5];
int jud[1000+5];//判断负环
int V;

int SPFA(){
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    jud[1]++;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        used[t] = 0;
        for(int i=0;i<ed[t].size();i++){
            int v = ed[t][i].first;
            if(dist[v]>dist[t]+ed[t][i].second){
                dist[v] = dist[t]+ed[t][i].second;
                if(!used[v]){
                    if(jud[v]>V){
                        return -1;
                    }
                    q.push(v);
                    used[v] = 1;
                    jud[v]++;
                }
            }
        }
    }
    if(dist[V]==INF) return -2;
    return dist[V];
}

int main(){
    int n,ml,md;
    scanf("%d%d%d",&n,&ml,&md);
    V = n;
    memset(dist,INF,sizeof(dist));
    memset(used,0,sizeof(used));
    memset(jud,0,sizeof(jud));
    int a,b,d;
    for(int i=0;i<ml;i++){
        scanf("%d%d%d",&a,&b,&d);
        ed[a].push_back(P(b,d));
    }
    for(int i=0;i<md;i++){
        scanf("%d%d%d",&a,&b,&d);
        ed[b].push_back(P(a,-d));
    }
    for(int i=1;i<n;i++){
        ed[i+1].push_back(P(i,0));
    }
    printf("%d",SPFA());

    return 0;
}

//https://vjudge.net/problem/POJ-3169