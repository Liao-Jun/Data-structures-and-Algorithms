#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<int,vector<int>,greater<int>> q;
    stack<int> v;
    int x;
    for(int i=0;i<m;i++){
        cin >> x;
        q.push(x);
    }
    int cnt = 0;
    int sum = m;
    if(n-q.top()<m-1){
        cout << -1;
    }else{
        x = q.top();
        q.pop();
        while(!q.empty()){
            if(x!=q.top()){
                if(q.top()-x>1&&!v.empty()){
                    int f = 1;
                    int t = q.top()-x-1;
                    while(t>0&&!v.empty()){
                        cnt += f+v.top()-x;
                        f++;
                        v.pop();
                        t--;
                    }
                }
                x = q.top();
                q.pop();
            }else{
                while(x==q.top()&&!q.empty()){
                    q.pop();
                    v.push(x);
                }
            }
        }
        x++;
        while(!v.empty()){
            int y = v.top();
            cnt += x-y;
            v.pop();
            x++;
        }
        cout << cnt << endl;
    }

    return 0;
}