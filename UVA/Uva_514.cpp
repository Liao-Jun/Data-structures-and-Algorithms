#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int n;
    int x[1000+5];
    while(cin >> n&&n!=0){
        while(cin >> x[0]&&x[0]!=0){
            for(int i=1;i<n;i++){
                cin >> x[i];
            }
            stack<int> y;
            int b = 0;
            for(int i=1;i<=n;i++){
                y.push(i);
                while(!y.empty()&&(y.top()==x[b])){
                    b++;
                    y.pop();
                }
            }
            if(b==n){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-514