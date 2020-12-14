// Problem:
// 某省自从实行了很多年的畅通工程计划后，终于修建了很多路。不过路多了也不好，每
// 次要从一个城镇到另一个城镇时，都有许多种道路方案可以选择，而某些方案要比另
// 一些方案行走的距离要短很多。这让行人很困扰。
// 现在，已知起点和终点，请你计算出要从起点到终点，最短需要行走多少距离。
// Input
// 本题目包含多组数据，请处理到文件结束。
// 每组数据第一行包含两个正整数N和M(0<N<200,0<M<1000)，分别代表现有城镇的数目和已修建的道路的数目。城镇分别以0～N-1编号。
// 接下来是M行道路信息。每一行有三个整数A,B,X(0<=A,B<N,A!=B,0<X<10000),表示城镇A和城镇B之间有一条长度为X的双向道路。
// 再接下一行有两个整数S,T(0<=S,T<N)，分别代表起点和终点。
// Output
// 对于每组数据，请在一行里输出最短需要行走的距离。如果不存在从S到T的路线，就输出-1.
// Sample Input
// 3 3
// 0 1 1
// 0 2 3
// 1 2 1
// 0 2
// 3 1
// 0 1 1
// 1 2
// Sample Output
// 2
// -1
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
vector<P> ed[M];//图的邻接表
int dist[M];//距离
int used[M];//点是否在队列里
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