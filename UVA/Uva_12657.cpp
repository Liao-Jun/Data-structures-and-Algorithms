#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    int k = 1;
    while(scanf("%d%d",&n,&m)==2){
        list<int> l(n);
        vector<list<int>::iterator> p(n+1);
        int i=1;
        for(auto q=l.begin();q!=l.end();q++,i++){
            *q = i;
            p[i] = q;
        }
        int flag,a,b;
        int re = -1;
        for(int i=0;i<m;i++){
            cin >> flag;
            if(flag==4){
                re = -1*re;
            }else if(flag==3){
                scanf("%d%d",&a,&b);
                swap(*p[a], *p[b]);
                swap(p[a], p[b]);
            }else{
                scanf("%d%d",&a,&b);
                if(re==1){
                    flag = 3-flag;
                }
                l.erase(p[a]);
                auto y = p[b];
                if(flag==2){
                    y++;
                }
                p[a] = l.insert(y, a);
            }
        }
        long long int sum = 0;
        if(re==-1){
            for(auto it=l.begin(); it!=l.end();it++,it++){
                sum += *it;
            }
            cout << "Case " << k++ << ": ";
            cout << sum << endl;
        }else{
            for(list<int>::reverse_iterator it=l.rbegin(); it!=l.rend();++it,++it){
                sum += *it;
            }
            cout << "Case " << k++ << ": ";
            cout << sum << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-12657