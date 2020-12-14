// problem:
// 求关于x的同余方程ax≡1(mod b) (ax mod b = 1)的最小正整数解。(ax+by=1)
// 输入格式
// 一行，包含两个正整数 a,b，用一个空格隔开。
// 输出格式
// 一个正整数 x0，即最小正整数解。输入数据保证一定有解。
// INPUT:
// 3 10
// OUTPUT:
// 7
#include <iostream>
#include <stdio.h>
#include <algorithm>

typedef long long ll;
ll x,y;

void exgcd(ll a, ll b){
    if(b==0){
        x = 1;
        y = 0;
        return;
    }else{
        exgcd(b,a%b);
    }
    ll x1 = x;
    x = y;
    y = x1-a/b*y;
    return;
}

int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    exgcd(a,b);
    while(x<0){
        x += b;
    }
    x %= b;
    printf("%lld\n",x);

    return 0;
}

//https://www.luogu.com.cn/problem/P1082