#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int t;
int n;
int x,y;
int graph[30][30];
int g[30];
string s;

bool dfs(int s){
    for(int i;i<26;i++){
        if(graph[s][i]==1&&s!=i){
            if(i==y){
                return true;
            }else{
                return dfs(i);
            }
        }
    }
    return false;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        fill(graph[0],graph[0]+30*30, 0);
        fill(g,g+30,0);
        for(int i=0;i<n;i++){
            cin >> s;
            g[s[0]-'a'] --;
            g[s[s.length()-1]-'a'] ++;
            graph[s[0]-'a'][s[s.length()-1]-'a'] = 1;
        }
        int flag = 0;
        int flag1 = 0;
        for(int i=0;i<30;i++){
            if(!(g[i]==0||g[i]==1||g[i]==-1)) {
                flag = 2;
                break;
            }
            if(g[i]==-1){
                flag++;
                x = i;
            }
            if(g[i]==1){
                flag1++;
                y = i;
            }
        }
        if(flag==2) cout << "The door cannot be opened.\n";
        else if(flag<=1&&flag1<=1){
            if(dfs(x)){
                cout << "Ordering is possible.\n";
            }else{
                cout << "The door cannot be opened.\n";
            }
        }else{
            cout << "The door cannot be opened.\n";
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-10129