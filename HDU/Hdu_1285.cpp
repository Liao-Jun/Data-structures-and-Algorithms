#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;

int n,m;
int d[500*2500][2];
vector<int> s;
unordered_map<int, int> r;

void dfs(){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        if(r[i]==0){
            q.push(i);
            r[i] = -1;
        }
    }
    while(!q.empty()){
        int b = q.top();
        q.pop();
        for(int i=0;i<m;i++){
            if(d[i][0]==b){
                r[d[i][1]] --;
            }
        }
        for(int i=1;i<=n;i++){
            if(r[i]==0){
                q.push(i);
                r[i] = -1;
            }
        }
        s.push_back(b);
    }
}

int main(){
    while(cin >> n >> m&&(n!=0||m!=0)){
        s.clear();
        r.clear();
        for(int i=1;i<=n;i++){
            r[i] = 0;
        }
        for(int i=0;i<m;i++){
            cin >> d[i][0] >> d[i][1];
            r[d[i][1]] ++;
        }
        dfs();
        for(auto it=s.begin();it!=s.end();++it){
            if(it+1==s.end()){
                cout << *it << endl;
                break;
            }
            cout << *it << ' ';
        }
    }
    return 0;
}

//https://vjudge.net/problem/HDU-1285