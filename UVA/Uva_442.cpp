#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

map<char, pair<int, int>> M;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    char c;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> c >> a >> b; 
        M.insert(pair<char, pair<int, int>>(c,pair<int, int>(a,b)));
    }
    string s;
    stack<char> p;
    int sum = 0;
    int count = 0;
    int flag = 0;
    while(cin >> s){
        if(s.length()==1){
            cout << '0' << endl;
            continue;
        }else{
            for(int i=0;i<s.length();i++){
                p.push(s[i]);
                if(p.top()==')'){
                    p.pop();
                    char j = p.top();
                    p.pop();
                    char k = p.top();
                    p.pop();
                    p.pop();
                    if(M[k].second != M[j].first){
                        cout << "error" <<endl;
                        flag = 1;
                        break;
                    }else{
                        sum += M[k].first*M[k].second*M[j].second;
                        M.insert(pair<char, pair<int, int>>(char(count), pair<int, int>(M[k].first, M[j].second)));
                        count++;
                    }
                }
            }
            if(flag == 1){
                flag = 0;
                continue;
            }
            cout << sum << endl;
            sum = 0;
            count = 0;
            while(!p.empty()){
                p.pop();
            }
        }
    }

    return 0;
}