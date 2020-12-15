#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long ll;

ll q_mul(ll a, ll b,ll mod){
    ll res;
    while(b>0){
        if(b&1) res += a%mod;
        a = (a*2)%mod;
        b>>=1;
    }
    return res%mod;
}

// 原理： 利用乘法分配率来将a＊b转化为多个式子相加的形式求解（注意这时使用乘法分配率的时候后面的一个乘数转化为二进制的形式计算）。
// 如：20＊14　＝　20＊(1110)2 = 20＊(2^3)＊1 + 20＊(2^2)＊1+20＊(2^1)＊１+20＊(2^0)＊0 = 160+80+40=280