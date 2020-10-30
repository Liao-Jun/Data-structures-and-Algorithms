#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

map<int, int> team;

int main(){
    int t;
    int l;
    int k=0;
    while(cin >> t&&t!=0){
        cout << "Scenario #" << ++k << endl;
        for(int i=0;i<t;i++){
            cin >> l;
            for(int j=0;j<l;j++){
                int x;
                cin >> x;
                team[x] = i;
            }
        }
        string s;
        int x;
        queue<int> q,q1[2000];
        while(cin >> s&&s[0]!='S'){
            if(s[0]=='E'){
                cin >> x;
                int y = team[x];
                if(q1[y].empty())q.push(y);
                q1[y].push(x);
            }else if(s[0]=='D'){
                int y = q.front();
                cout << q1[y].front() << endl;
                q1[y].pop();
                if(q1[y].empty()){
                    q.pop();
                }
            }
        }
        cout << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-540