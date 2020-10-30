#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[7+5];
        for(int i=0;i<7;i++){
            cin >> a[i];
        }
        getchar();
        queue<string> q[1000+5];
        deque<int> q1;
        queue<int> q2;
        int sum = 0;
        for(int i=0;i<a[0];i++){
            string s;
            while(getline(cin, s)){
                if(s[2] == 'd'){
                    sum++;
                    q[sum-1].push(s);
                    q1.push_back(sum-1);
                    break;
                }
                q[sum].push(s);
            }
        }
        map<char, char> m;
        int time = a[6];
        int Lock = 0;
        while(!q1.empty()){
            int a1 = q1.front();
            if(q[a1].front()[2] == '='){
                if(m.find(q[a1].front()[0]) == m.end()){
                    m[q[a1].front()[0]] == q[a1].front()[4];
                }
                m.insert(pair<char, char>(q[a1].front()[0],q[a1].front()[4]));
                q[a1].pop();
                time = time - a[1];
                if(time == 0){
                    if(!q[a1].empty()){
                        q1.pop_front();
                        q1.push_back(a1);
                    }else{
                        q1.pop_front();
                    }
                    time = a[0];
                }
                for(auto it=m.begin();it!=m.end();++it){//dubug
                    cout << "??" << it->first << it->second << endl;//debug
                }//debug
            }else if(q[a1].front()[0] == 'p'){
                cout << a1+1 << ": " << m[q[a1].front()[6]] << endl;
                q[a1].pop();
                time = time - a[2];
                if(time == 0){
                    if(!q[a1].empty()){
                        q1.pop_front();
                        q1.push_back(a1);
                    }else{
                        q1.pop_front();
                    }
                    time = a[0];
                }
            }else if(q[a1].front()[0] == 'l'){
                if(Lock == 0){
                    Lock++;
                    q[a1].pop();
                    time = time -a[3];
                    if(time == 0){
                        if(!q[a1].empty()){
                            q1.pop_front();
                            q1.push_back(a1);
                        }else{
                            q1.pop_front();
                        }
                        time = a[0];
                    }
                }else if(Lock == 1){
                    q[a1].pop();
                    q1.pop_front();
                    q2.push(a1);
                    time = time - a[3];
                    if(time == 0){
                        time = a[0];
                    }
                }
            }else if(q[a1].front()[0] == 'u'){
                int b = q2.front();
                q2.pop();
                q1.push_front(b);
                q[a1].pop();
                time = time - a[4];
                if(time == 0){
                    if(!q[a1].empty()){
                        q1.pop_front();
                        q1.push_back(a1);
                    }else{
                        q1.pop_front();
                    }
                    time = a[0];
                }
            }else if(q[a1].front()[0] == 'e'){
                q1.pop_front();
                q[a1].pop();
                time = time -a[5];
                if(time == 0){
                    time = a[0];
                }
            }
        }
    }

    return 0;
}