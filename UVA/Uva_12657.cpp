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
            scanf("%d",&flag);
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
        long long int count = 1,sum = 0;
        for(auto it =l.begin();it!=l.end();++it,++count){
            if(count%2 ==1)sum+=*it;
        }
        if(re==1){
            sum = 1ll*(n+1)*n/2 - sum;
        }
        printf("Case %d: %lld\n",k++,sum);
    }

    return 0;
}

//https://vjudge.net/problem/UVA-12657