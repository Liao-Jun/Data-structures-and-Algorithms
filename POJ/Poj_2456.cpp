#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
int x[M];
int n,c;

bool check(int m){
    int cnt = 1;
    int now = x[0];
    for(int i=1;i<n;i++){
        if(x[i]-now>=m){
            cnt++;
            now = x[i];
        }
        if(cnt==c) return true;
    }
    return false;
}

int main(){
    while(~scanf("%d%d",&n,&c)){
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
        }
        sort(x,x+n);
        int du = 0,dl = INF;
        while((dl-du)>1){
            int mid = (du+dl)/2;
            if(check(mid)) du = mid;
            else dl = mid;
        }
        printf("%d\n",du);
    }

    return 0;
}

//https://vjudge.net/problem/POJ-2456