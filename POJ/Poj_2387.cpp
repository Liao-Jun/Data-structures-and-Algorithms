#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int cost[1010][1010];
int used[1010];
int dist[1010];
int V;

void Dijkstra(){
    int k,min;
    for(int i=1;i<=V;i++){
        dist[i] = cost[1][i];
        used[i] = 0;
    }
    for(int i=1;i<=V;i++){
        k = 0;
        min = INF;
        for(int j=1;j<=V;j++){
            if(used[j]==0&&dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        used[k] = 1;
        for(int j=1;j<=V;j++){
            if(used[j]==0&&dist[k]+cost[k][j]<dist[j]){
                dist[j] = dist[k]+cost[k][j];
            }
        }
    }
    return;
}

int main(){
    int t,n;
    cin >> t >> n;
    int x,y,z;
    memset(used,0,sizeof(used));
    memset(dist,0,sizeof(dist));
    V = n;
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            cost[i][j] = INF;
        }
    }
    for(int i=1;i<=t;i++){
        cin >> x >> y >> z;
        if(z<cost[x][y]){
            cost[x][y] = z;
            cost[y][x] = z;
        }
    }
    Dijkstra();
    cout << dist[V] << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-2387