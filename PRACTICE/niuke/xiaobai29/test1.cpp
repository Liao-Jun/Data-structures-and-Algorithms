#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1E+6;
int a[M];

struct Node
{
    long long int d = 0;
    long long int v = 0;
};

Node x[M];

bool cmp(const Node &a, const Node &b){
    return a.v > b.v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long long int c;
    for(int i=0;i<m;i++){
        cin >> c;
        x[i].d = c;
    }
    for(int i=0;i<m;i++){
        cin >> c;
        x[i].v = c;
    }
    sort(x,x+m,cmp);
    long long int sum = 0;
    for(int i=0;i<m;i++){
        if(x[i].v<=0){
            m = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]>x[j].d){
                if(x[j].d<=0){
                    break;
                }else{
                    sum += x[j].v;
                    break;
                }
            }
        }
    }
    printf("%lld",sum);

    return 0;
}
