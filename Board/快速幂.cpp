// problem:
// 三个整数 b,p,k,求 b^p mod k
// 格式
// 输入只有一行三个整数，分别代表 b,p,k
// 输出格式
// 输出一行一个字符串 b^p mod k=s，其中 b, p, k 分别为题目给定的值， s为运算结果
// INPUT:
// 2 10 9
// OUTPUT:
// 2^10 mode 9 = 7
// Hint:
// 0<b,p<2^31,1<=k<=2^31
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll mpow(ll b,ll p,ll k){//a^b
    ll res = 1;
    while(p>0){
        if(p&1) res=res*b%k;
        b = b*b%k;
        p>>=1;
    }
    return res;
}

int main(){
    ll b,p,k;
    scanf("%lld%lld%lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=%lld\n",b,p,k,mpow(b,p,k)%k);

    return 0;
}

//https://www.luogu.com.cn/problem/P1226