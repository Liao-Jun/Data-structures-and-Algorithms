#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
int n,k;
int v[M],w[M];

struct s{
    double x;
    int id;
}y[M];

bool cmp(const s &a,const s &b){
    return a.x>b.x;
}

bool solve(double x){
    for(int i=0;i<n;i++){
        y[i].id = i;
        y[i].x = v[i]-x*w[i];
    }
    sort(y,y+n,cmp);
    double sum = 0;
    for(int i=0;i<k;i++){
        sum += y[i].x;
    }
    return sum >= 0;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    double du = 0, dl = INF;
    while(dl-du>=1e-6){
        double mid = (du+dl)/2;
        if(solve(mid)) du = mid;
        else dl = mid;
    }
    for(int i=0;i<k-1;i++){
        cout << y[i].id+1 << ' ';
    }
    cout << y[k-1].id+1 << endl;

    return 0;
}

//https://vjudge.net/problem/POJ-3111