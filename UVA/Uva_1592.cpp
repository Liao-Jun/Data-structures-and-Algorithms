#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
map<string, int> ID;
vector<string> GetStr;
vector<int> table[10000+5];

int GoID(string str){
    if(ID.count(str)==0){
        GetStr.push_back(str);
        return ID[str] = ID.size();
    }else{
        return ID[str];
    }
}

int main(){
    ios::sync_with_stdio(false);

    while(scanf("%d%d",&n,&m)!=EOF){
        string str;
        char s;
        getchar();
        for(int i=0;i<n;i++){
            while(1){
                s = getchar();
                if(s=='\n'){
                    if(!str.empty()){
                        table[i].push_back(GoID(str));
                        str.clear();
                        break;
                    }
                }
                else if(s==' '){
                        continue;
                }else if(s==','){
                    table[i].push_back(GoID(str));
                    str.clear();
                }else{
                    str += s;
                }
            }
        }
        int C1,C2;
        int R1,R2;
        int flag = 0;
        pair<int, int> Un[10000+5];
        for(int c1=0;c1<m;c1++){
            for(int c2 = 0;c2<c1;c2++){
                for(int r1=0;r1<n;r1++){
                    Un[r1].first = table[r1][c1];
                    Un[r1].second = table[r1][c2];
                    for(int r2=0;r2<r1;r2++){
                        if(Un[r2]==Un[r1]){
                            flag = 1;
                            R2 = r2+1;
                            R1 = r1+1;
                            break;
                        }
                    }
                    if(flag==1){
                        C2 = c2+1;
                        C1 = c1+1;
                        break;
                    }
                }
                if(flag==1){
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
            cout << R2 << ' ' << R1 << endl;
            cout << C2 << ' ' << C1 << endl;
        }
        ID.clear();
        GetStr.clear();
        for(int i=0;i<n;i++){
            table[i].clear();
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1592