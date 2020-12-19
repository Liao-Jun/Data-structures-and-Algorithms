#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int M = 1e4+5;
const int INF = 0x3f3f3f3f;
double L[M];
int n,k;

bool check(double m){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += (int)(L[i]/m);
    }
    return sum>=k;
}

int main(){
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++){
            scanf("%lf",&L[i]);
        }
        double dl = 0,du = INF;
        for(int i=0;i<100;i++){
            double mid = (dl+du)/2;
            if(check(mid)){
                dl = mid;
            }else{
                du = mid;
            }
        }
        printf("%.2f\n",floor(du*100)/100);
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1064