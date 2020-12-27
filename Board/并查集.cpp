// Problem
// 警察抓贩毒集团。有不同类型的犯罪集团，人员可能重复，集团内的人会相互
// 接触。现在警察在其中一人（0号）身上搜出毒品，认为与这个人直接接触或通过其
// 他人有间接接触的人都是嫌疑犯。问包括0号犯人共有多少嫌疑犯？
// Input
// 多样例输入。
// 每个测试用例以两个整数n和m开头，其中n为人数，m为犯罪集团数。你可以假定
// 0 < n <= 30000和0 <= m <= 500。在所有的情况下，每个人都有自己独特的整数编号
// 0到n−1, 且0号是公认的嫌疑犯。接下来m行输入，每个犯罪集团一行。每一行从一个整数
// k开始，它本身表示集团内成员的数量。按照成员的数量，在这个组中有k个整数表示
// 人员。一行中的所有整数都被至少一个空格隔开。
// n = 0且m = 0时输入结束。
// Output
// 对于每个样例，输出嫌疑犯人数。
// Sample Input
// 100 4
// 2 1 2
// 5 10 13 11 12 14
// 2 0 1
// 2 99 2
// 200 2
// 1 5
// 5 1 2 3 4 5
// 1 0
// 0 0
// Sample Output
// 4
// 1
// 1
#include <iostream>
#include <cstring>
using namespace std;

const int M = 3e5+5;
int pre[M];

int find_root(int x){
    return pre[x]==x?x:pre[x]=find_root(pre[x]);
}

void join(int x, int y){
    int rx = find_root(x);
    int ry = find_root(y);
    if(rx!=ry){
        pre[rx] = ry;
    }
}

int main(){
    int n,m,k;
    while(cin>>n>>m&&!(n==0&&m==0)){
        for(int i=0;i<M;i++){
            pre[i] = i;
        }
        for(int i=0;i<m;i++){
            cin >> k;
            int a,b;
            for(int j=0;j<k;j++){
                cin >> a;
                if(j==0){
                    b=a;
                    continue;
                }
                join(a,b);
            }
        }
        int root = find_root(0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(find_root(i)==root){
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}

//https://vjudge.net/problem/POJ-1611