#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    while(scanf("%d",&k)==1){
        int y,x;
        vector<int> X,Y;
        int cnt = 0;
        for(int i=(k+1);i<=(2*k);i++){
            if((k*i)%(i-k)==0){
                y = i;
                x = (k*i)/(i-k);
                X.push_back(x);
                Y.push_back(y);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(auto it1=X.begin(),it2=Y.begin();it1!=X.end();++it1,++it2){
            printf("1/%d = 1/%d + 1/%d\n",k,*it1,*it2);
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-10976