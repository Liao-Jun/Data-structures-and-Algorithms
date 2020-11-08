#include <iostream>
#include <string>
using namespace std;

int t,n;
string s;
int graph[26][26];
int in[26];
int out[26];
bool v[26];

void dfs(int k){
    v[k] = true;
    for(int i=0;i<26;i++){
        if(graph[k][i]&&!v[i]) dfs(i);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        fill(graph[0],graph[0]+26*26,0);
        fill(in,in+26,0);
        fill(out,out+26,0);
        fill(v,v+26,false);
        for(int i=0;i<n;i++){
            cin >> s;
            int a = s[0]-'a';
            int b = s[s.length()-1]-'a';
            graph[a][b] = 1;
            out[a] ++;
            in[b] ++;
        }
        bool flag = true;
        int a=0,b=0;
        for(int i=0;i<26;i++){
            if(in[i]!=out[i]){
                if(in[i]==out[i]+1) a++;
                else if(in[i]+1==out[i]) b++;
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(a&&b&&a+b>2) flag = false;
        if(flag){
            if(a+b==2){
                for(int i=0;i<26;i++){
                    if(out[i]&&(out[i]-in[i])==1){
                        dfs(i);
                        break;
                    }
                }
            }else{
                for(int i=0;i<26;i++){
                    if(out[i]){
                        dfs(i);
                        break;
                    }
                }
            }
            bool flag1 = true;
            for(int i=0;i<26;i++){
                if(out[i]&&!v[i]){
                    flag1 = false;
                    cout <<i;
                    break;
                }
                if(in[i]&&!v[i]){
                    flag1 = false;
                    break;
                }
            }
            if(flag1){
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