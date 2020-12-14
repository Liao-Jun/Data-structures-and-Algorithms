#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 200+5;
typedef pair<int,int> P;
vector<P> ed[M];
int dist[M];
int used[M];
int n,m,s,t;

void SPFA(){
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    used[s] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        used[x] = 0;
        for(int i=0;i<ed[x].size();++i){
            int v = ed[x][i].first;
            if(dist[v]>dist[x]+ed[x][i].second){
                dist[v] = dist[x]+ed[x][i].second;
                if(!used[v]){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    int a,b,c;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<M;i++){
            ed[i].clear();
        }
        memset(dist,INF,sizeof(dist));
        memset(used,0,sizeof(used));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            ed[a].push_back(P(b,c));
            ed[b].push_back(P(a,c));
        }
        scanf("%d%d",&s,&t);
        SPFA();
        printf("%d\n",dist[t]==INF?-1:dist[t]);
    }

    return 0;
}

//https://vjudge.z180.cn/problem/HDU-1874