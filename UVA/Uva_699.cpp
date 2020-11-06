#include <iostream>
#include <map>
using namespace std;

map<int, int> sum;

void CreatTree(int p){
    int x;
    cin >> x;
    if(x!=-1){
        sum[p] += x;
        CreatTree(p-1);
        CreatTree(p+1);
    }
}

int main(){
    int flag = 0;
    while(1){
        sum.clear();
        CreatTree(0);
        if(sum.empty()) break;
        if(flag++!=0){
            cout << endl;
        }
        cout << "Case " << flag << ":\n";
        for(auto x:sum){
            printf("%d",x.second);
            if(x.first==sum.rbegin()->first){
                cout << endl;
            }else{
                cout << ' ';
            }
        }
    }
    cout << endl;
    return 0;
}

//https://vjudge.net/problem/UVA-699