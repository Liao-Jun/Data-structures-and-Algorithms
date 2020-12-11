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
// Sample Input:
// 5 5
// 1 2 20
// 2 3 30
// 3 4 20
// 4 5 20
// 1 5 100
// Sample Output:
// 90
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

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

int V;
int dist[1010];
int used[1010];
vector<node> e[1010];

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
            if(dist[u]+cost<dist[v]&&used[v]==0){
                dist[v] = dist[u]+cost;
                q.push(Node(v,dist[v]));
            }
        }
    }

}

int main(){
    int t,n;
    cin >> t >> n;
    V = n;
    memset(dist,INF,sizeof(dist));
    memset(used,0,sizeof(used));
    int x,y,z;
    for(int i=1;i<=t;i++){
        cin >> x >> y >> z;
        e[x].push_back(node(y,z));
        e[y].push_back(node(x,z));
    }
    Dijkstra();
    cout << dist[V] << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-2387