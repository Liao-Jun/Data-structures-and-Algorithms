#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a;
    vector<int> v;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        v.push_back(a);
    }
    string s;
    int x,y;
    while(m--){
        cin >> s;
        scanf("%d%d",&x,&y);
        if(s[0]=='A'){
            int Max = 0;
            map<int, int> dic;
            for(int i=x-1;i<=y-1;i++){
                Max = max(Max,v[i]);
                dic[v[i]] ++;
            }
            cout << Max << ' ' << dic[Max] << endl;
        }else if(s[0]=='C'){
            v[x-1] = y;
        }
    }

    return 0;
}