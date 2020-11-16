#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
    int re = 1,n,m;
    cin >> n >> m;
    int i=1;
    list<int> l(n);
    vector<list<int>::iterator> v(n+1);
    for(auto it=l.begin();it!=l.end();++it){
        *it=i;
        v[i]=it;
        i++;
    }
    int op,a,b;
    for(int i=0;i<m;i++){
        cin >> op;
        if(op==4){
            vector<int> x;
            if(re==1){            
                for(auto it=l.begin();it!=l.end();++it){
                    x.push_back(*it);
                }
                for(auto it=l.begin();it!=l.end();++it){
                    x.push_back(*it);
                }
            }else{
                for(auto it=l.rbegin();it!=l.rend();++it){
                    x.push_back(*it);
                }
                for(auto it=l.rbegin();it!=l.rend();++it){
                    x.push_back(*it);
                }
            }
            cout << 1;
            int flag = -1;
            int cnt = 1;
            for(int j=0;j<x.size();j++){
                if(flag==1&&cnt<n){
                    cout << ' ' << x[j];
                    cnt++;
                }
                if(x[j]==1){
                    flag *= -1;
                }
            }
            cout << endl;
        }else if(op==3){
            re *= -1;
        }else{
            cin >> a >> b;
            if(re==-1){
                op = 3-op;
            }
            int a1,b1;
            for(int j=1;j<n+1;j++){
                if(*(v[j])==a){
                    a1 = j;
                }
                if(*(v[j])==b){
                    b1 = j;
                }
            }
            l.erase(v[a1]);
            auto p = v[b1];
            if(op==1){
                p++;
            }
            v[a1] = l.insert(p,a);
        }
    }

    return 0;
}