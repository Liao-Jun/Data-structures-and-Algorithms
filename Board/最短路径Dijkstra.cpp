// Problem:
// 大佬要去找他的女朋友，但是他不知道他的女朋友在哪一个公交站。
// 开封市里有N个(2 <= N <= 1000)个公交站，编号分别为1..N。公交
// 站1是女朋友的位置,大佬所在的位置是N。所有公交站中共有T (1 <= T <= 2000)
// 条双向通道。大佬对自己的导航能力不太自信，所以一旦开始，他总是沿着一条路线走到底。
// 根据站台之间的道路，确定大佬找到他女朋友必须走的最小距离。可以保证存在这样的路存在。
// Input:
// 第一行:两个整数:T和N
// 接下来T行:每一行都用三个空格分隔的整数描述一个轨迹。前两个整数是路线经过的公交站台。第三个整数是路径的长度，范围为1到100。
// Output:
// 一个整数，表示大佬找到他女朋友的最小距离。
// Sample Input
// 5 5
// 1 2 20
// 2 3 30
// 3 4 20
// 4 5 20
// 1 5 100
// Sample Output
// 90
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