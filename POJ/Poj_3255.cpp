#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 5e3+10;

struct node{
	int v,cost;
	node(int _v, int _cost):v(_v),cost(_cost){};
};

struct Node{
	int point,dist,s;
	Node(int _point, int _dist,int _s):point(_point),dist(_dist),s(_s){};
	bool operator<(const Node &a) const{
		return dist>a.dist;
	}
};

int dist[M][2];
int used[M][2];
int V;
vector<node> e[M];

void Dijkstra(){
	priority_queue<Node> q;
	dist[1][0] = 0;
	q.push(Node(1,0,0));
	while(!q.empty()){
		Node temp = q.top();
		q.pop();
		int u = temp.point;
		int s = temp.s;
		if(dist[u][1]<temp.dist){
			continue;
		}
		used[u][s] = 1;
		for(int i=0;i<e[u].size();i++){
			int v = e[u][i].v;
			int cost = e[u][i].cost;
			if(cost+dist[u][0]<dist[v][0]){
				dist[v][1] = dist[v][0];
				dist[v][0] = cost+dist[u][0];
				q.push(Node(v,dist[v][0],0));
				q.push(Node(v,dist[v][1],1));
			}else if(cost+dist[u][0]<dist[v][1]&&cost+dist[u][0]>dist[v][0]){
				dist[v][1] = cost+dist[u][0];
				q.push(Node(v,dist[v][1],1));
			}
		}
	}
}

int main(){
	int n,r;
	cin >> n >> r;
	int x,y,z;
	V = n;
	memset(dist,INF,sizeof(dist));
	memset(used,0,sizeof(used));
	for(int i=1;i<=r;i++){
		cin >> x >> y >> z;
		e[x].push_back(node(y,z));
		e[y].push_back(node(x,z));
	}
	Dijkstra();
	cout << dist[V][1] << endl;

	return 0;
}