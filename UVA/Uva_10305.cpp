#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int n,m;
int d[10000][2];
unordered_map<int, int> r;

void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(r[i]==0){
            q.push(i);
            r[i] = -1;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<m;i++){
            if(d[i][0]==x){
                r[d[i][1]] --;
            }
        }
        for(int i=1;i<=n;i++){
            if(r[i]==0){
                q.push(i);
                r[i] = -1;
            }
        }
        cout << x << ' ';
    }
}

int main(){
    while(cin >> n >> m&&(n!=0||m!=0)){
        for(int i=1;i<=n;i++){
            r[i] = 0;
        }
        for(int i=0;i<m;i++){
            cin >> d[i][0] >> d[i][1];
            r[d[i][1]] ++;
        }
        bfs();
        cout << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-10305