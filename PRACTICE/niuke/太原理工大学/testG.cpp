#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#define endl '\n'
#define PI acos(-1)
// #define DEBUG
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9+7;
const int EXP = 1e-8;
// inline ll gcd(ll x, ll y){if(y==0) return x;return gcd(y,x%y);}//x>y
inline void debug(){printf("@@\n");}
bool cmp(const pair<string,P> &a,const pair<string,P> &b){
    if(a.second.first!=b.second.first){
        return a.second.first>b.second.first;
    }else{
        if(a.second.second!=b.second.second){
            return a.second.second>b.second.second;
        }else{
            return a.first<=b.first;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("C://Users//24887//Data-structures-and-Algorithms//input.in","r",stdin);
        freopen("C://Users//24887//Data-structures-and-Algorithms//output.out","w",stdout);
    #endif
    int n,k;
    cin >> n >> k;
    map<string, int> dic;
    string s;
    int x;
    for(int i=0;i<n;i++){
        cin >> s >> x;
        dic[s] = x;
    }
    int m;
    cin >> m;
    string sn,sa;
    int t;
    map<string,P> d;
    map<string,int> flag;
    for(int i=0;i<m;i++){
        cin >> sn >> t;
        d[sn].first = 0;
        d[sn].second = 0;
        while(t--){
            cin >> sa;
            if(dic[sa]!=0){
                d[sn].first += dic[sa];
                if(d[sn].first>=k) flag[sn] = 1;
                if(dic[sa]>0)d[sn].second ++;
            }
        }
    }
    vector<pair<string,P>> v;
    for(auto it=d.begin();it!=d.end();++it){
        if(flag[it->first]==1){
            v.push_back(make_pair(it->first,make_pair(it->second.first,it->second.second)));
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it=v.begin();it!=v.end();++it){
        cout << it->first << ' ' << it->second.first << endl;
    }

    return 0;
}