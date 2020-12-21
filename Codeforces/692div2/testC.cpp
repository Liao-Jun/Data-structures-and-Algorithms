#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

const int M = 2e5+10;
int n,m;
pair<int,int> p[M];
map<int,int> dic;

struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return (dic[a.first]+dic[a.second])<(dic[b.first]+dic[b.second]);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        dic.clear();
        cin >> n >> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        for(int i=0;i<m;i++){
            scanf("%d%d",&p[i].first,&p[i].second);
            dic[p[i].first] ++;
            dic[p[i].second] ++;
            q.push(p[i]);
        }
        int sum = 0;
        while(!q.empty()){
            pair<int,int> p1;
            p1 = q.top();
            q.pop();
            if(p1.first==p1.second) continue;
            if(dic[p1.first]==1&&dic[p1.second]==1){
                sum++;
                dic[p->second] --;
            }else if(dic[p1.first]==1&&dic[p1.second]!=1){
                sum++;
                dic[p1.second] --;
            }else if(dic[p1.first]>=1&&dic[p1.second]==1){
                sum++;
                dic[p1.first] --;
            }else{
                sum+=2;
                dic[p1.first] --;
                dic[p1.second] --;
            }
        }
        cout << sum << endl;
    }

    return 0;
}