#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node{
    int B, t;
};

struct cmp{
    bool operator()(node a, node b)const{
        if(a.B==b.B){
            return a.t>b.t;
        }
        return a.B<b.B;
    }
};

int main(){
    int n;
    int A,B;
    char x[5];
    priority_queue<node,vector<node>,cmp> a,b,c;
    while((cin>>n)&&n){
        int t = 0;
        for(int i=0;i<n;i++){
            cin >> x;
            if(x[0]=='I'){
                scanf("%d%d",&A,&B);
                t++;
                node y;
                y.B=B;
                y.t=t;
                if(A==1){
                    a.push(y);
                }else if(A==2){
                    b.push(y);
                }else{
                    c.push(y);
                }
            }else if(x[0]=='O'){
                scanf("%d",&A);
                if(A==1){
                    if(!a.empty()){
                        cout << a.top().t;
                        a.pop();
                    }else{
                        cout << "EMPTY";
                    }
                }else if(A==2){
                    if(!b.empty()){
                        cout << b.top().t;
                        b.pop();
                    }else{
                        cout << "EMPTY";
                    }
                }else if(A==3){
                    if(!c.empty()){
                        cout << c.top().t;
                        c.pop();
                    }else{
                        cout << "EMPTY";
                    }
                }
                cout << endl;
            }
        }
        while(!a.empty()){
            a.pop();
        }
        while(!b.empty()){
            b.pop();
        }
        while(!c.empty()){
            c.pop();
        }
    }

    return 0;
}