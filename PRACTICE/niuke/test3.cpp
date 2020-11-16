#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    list<int> l(n);
    vector<list<int>::iterator> p(n+1);
    int i = 1;
    for(auto it=l.begin();it!=l.end();++it){
        *it = i++;
        p[i-1] = it;
    }
    int t,a,b;
    int re = -1;
    while(m--){
        cin >> t;
        if(t==3){
            re = 1;
        }else if(t==4){
            cout << '1';
            vector<int> v;
            if(re==-1){
                for(auto it=l.begin();it!=l.end();++it){
                    v.push_back(*it);
                }
            }else{
                for(auto it=l.rbegin();it!=l.rend();++it){
                    v.push_back(*it);
                }
            }
            int i;
            for(i=0;i<v.size();i++){
                if(v[i]==1){
                    break;
                }
            }
            if(i!=v.size()-1){
                for(int j=i+1;j<v.size();j++){
                    cout << ' ' << v[j];
                }
            }
            if(i!=0){
                for(int j=0;j<i;j++){
                    cout << ' ' << v[j];
                }
            }
            cout << endl;
        }else{
            cin >> a >> b;
            if(re==1){
                t = 3-t;
            }
            l.erase(p[a]);
            auto q = p[b];
            if(t==1){
                q++;
            }
            p[a] = l.insert(q,a);
        }
    }

    return 0;
}