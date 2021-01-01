#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int M = 1e4+10;
int cost[M][M];
int used[M];
ll dist[M];
int V;

void Dijkstra(){
    int k,min;
    for(int i=0;i<=V;i++){
        dist[i] = cost[0][i];
        // cout << i << ' ' << dist[i] << endl;//debug
        used[i] = 0;
    }
    for(int i=1;i<=V;i++){
        k = 0;
        min = INF;
        for(int j=0;j<=V;j++){
            if(used[j]==0&&dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // cout << k << '@' << endl;//debug
        used[k] = 1;
        for(int j=0;j<=V;j++){
            if(used[j]==0&&1ll*dist[k]+1ll*cost[k][j]<1ll*dist[j]){
                dist[j] = 1ll*dist[k]+1ll*cost[k][j];
            }
        }
    }
    return;
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
    int x,y,z;
    memset(used,0,sizeof(used));
    memset(dist,INF,sizeof(dist));
    V = n;
    for(int i=0;i<=V;i++){
        for(int j=0;j<=V;j++){
            cost[i][j] = INF;
        }
    }
    for(int i=1;i<=t;i++){
        cin >> x >> y >> z;
        // cout << x << y << z << endl;//debug
        if(z<cost[x][y]){
            // cout << '#' << endl;//debug
            cost[x][y] = z;
        }
    }
    Dijkstra();
    pair<int,ll> p[V];
    for(int i=1;i<=V;i++){
        p[i-1].first = i;
        p[i-1].second = dist[i];
    }
    sort(p,p+V,cmp);
    cout << p[0].second << ' ' << p[0].first << endl;

    return 0;
}