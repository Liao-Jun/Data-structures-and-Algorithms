#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1e5+10;
int n;
int a[M];
typedef long long ll;

bool judge1(){
    int x = a[1] - a[0];
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=x){
            return false;
        }
    }
    return true;
}

bool judge2(){
    int x = (a[1]/a[0]);
    for(int i=2;i<n;i++){
        if((a[i]/a[i-1])!=x){
            return false;
        }
    }
    return true;
}

bool judge3(){
    int x = a[1]%a[0];
    for(int i=2;i<n;i++){
        if(a[i]%a[i-1]!=x){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    if(judge1()||judge2()||judge3()){
        printf("YES\n");
    }else printf("NO\n");

    return 0;
}