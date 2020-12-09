#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;
const int M = 2e5+10;
int a[M];

bool cmp(const pair<int, ll> &a, const pair<int, ll> &b){
    return a.second>b.second;
}

int main(){
    int n;
    scanf("%d",&n);
    map<int,int> dic;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        dic[a[i]]++;
    }
    vector<pair<int,ll>> p;
    int cnt = 0;
    for(auto it=dic.begin();it!=dic.end();++it){
        p.push_back(make_pair(it->first,1ll*it->first*it->second));
        cnt++;
    }
    sort(p.begin(),p.end(),cmp);
    int v[M];
    memset(v,0,n);
    ll sum = 0;
    for(auto it=p.begin();it!=p.end();++it){
        if(it==p.begin()){
            sum += it->second;
            v[it->first+1] = 1;
            v[it->first-1] = 1;
        }else if(v[it->first]==0){
            sum += it->second;
            v[it->first+1] = 1;
            v[it->first-1] = 1;
        }
    }
    cout << sum << endl;

    return 0;
}