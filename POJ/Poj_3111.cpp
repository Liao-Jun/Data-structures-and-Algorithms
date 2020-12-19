#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 0x3f3f3f3f;
const int M = 1e5+10;
int v[M],w[M];
double y[M];
int n,k;

bool judge(double x){
    for(int i=0;i<n;i++){
        y[i] = v[i]-x*w[i];
    }
    sort(y,y+n,greater<double>());
    double sum = 0;
    for(int i=0;i<k;i++){
        sum += y[i];
    }
    return sum >= 0;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    double du = 0,dl = INF;
    for(int i=0;i<100;i++){
        double mid = (du+dl)/2;
        if(judge(mid)){
            du = mid;
        }else dl = mid;
    }

    return 0;
}