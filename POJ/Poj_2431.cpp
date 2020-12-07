#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}

struct cmp1{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
};

int main(){
    int n;
    pair<int,int> a[10000+5];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    int k,f;
    cin >> k >> f;
    sort(a,a+n,cmp);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> q;
    int cnt = 0;
    int snt = 0;
    int K = k;
    for(int i=0;i<k;i++){
        if(f<=0){
            snt = -1;
            break;
        }
        f --;
        K --;
        if(K==a[cnt].first){
            q.push(a[cnt]);
            cnt++;
        }
        if(f==0&&K==0){
            break;
        }
        if(f==0){
            if(q.empty()){
                snt = -1;
                break;
            }else{
                f += q.top().second;
                snt ++;
                q.pop();
            }
        }
    }
    cout << snt << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-2431