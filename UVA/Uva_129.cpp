#include <iostream>
#include <vector>
using namespace std;

int n,l;
vector<int> v;

bool isHard(int c){
    v.push_back(c);
    for(int i=1;i<=v.size()/2;i++){
        int eq = 0;
        for(int j=0;j<i;j++){
            if(v[v.size()+j-i]!=v[v.size()-i*2+j]){
                eq = 1;
                break;
            }
        }
        if(!eq){
            v.pop_back();
            return false;
        }
    }
    return true;
}

void dfs(int &cnt){
    if(cnt==n){
        for(int i=0;i<v.size();i++){
            printf("%c",'A'+v[i]);
            if(i%64==63&&i!=0) printf("\n");
            else if(i==v.size()-1) printf("\n");
            else if(i%4==3) printf(" ");
        }
        printf("%d\n",v.size());
        return;
    }
    for(int i=0;i<l&&cnt<=n;i++){
        if(isHard(i)){
            dfs(++cnt);
            v.pop_back();
        }
    }
}

int main(){
    while(cin >> n >> l&&n!=0&&l!=0){
        v.clear();
        int sum = 0;
        dfs(sum);
    }

    return 0;
}

//https://vjudge.net/problem/UVA-129