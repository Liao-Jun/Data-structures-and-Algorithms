#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int M = 1e6+10;
int a[M];
int p;
set<int> all;
map<int,int> dic;

int main(){
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        scanf("%d",&a[i]);
        all.insert(a[i]);
    }
    int res = p;
    int sum = all.size();
    int t = 0,s = 0,num = 0;
    for(;;){
        while(t<p&&num<sum){
            if(dic[a[t++]]++ == 0){
                num++;
            }
        }
        if(num<sum) break;
        res = min(res, t-s);
        if(--dic[a[s++]] == 0){
            num--;
        }
    }
    printf("%d\n",res);

    return 0;
}