#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> x1;
    vector<int> x2(n+100);
    int a;
    x1.push_back(0);
    for(int i=1;i<=n;i++){
        cin >> a;
        x1.push_back(a);
    }
    int flag,x,y;
    while(q--){
        cin >> flag;
        if(flag==1){
            cin >> x;
            for(int i=x;i<=x1.size()-1;i++){
                x1[i]=x1[i+1];
            }
            x1.pop_back();
            cout << x1[1];
            for(int i=2;i<=x1.size()-1;i++){
                cout << ' ' << x1[i];
            }
            cout << endl;
        }else if(flag==2){
            cin >> x >> y;
            for(int i=1;i<=x1.size()-1;i++){
                x2[i]=x1[i];
            }
            int r = x1[x1.size()-1];
            x1[x] = y;
            for(int i=x+1;i<=x1.size()-1;i++){
                x1[i]=x2[i-1];
            }
            x1.push_back(r);
            cout << x1[1];
            for(int i=2;i<=x1.size()-1;i++){
                cout << ' ' << x1[i];
            }
            cout << endl;
            x2.clear();
        }else if(flag==3){
            cin >> x;
            int cnt = 0;
            for(int i=x,j=x+1;i<=x1.size()-1;i++,j++){
                if(i==x){
                    while(x1[i]==x1[x]){
                        i++;
                        cnt++;
                    }
                    x1[x] = x1[x]*(i-x);
                }
                x1[j] = x1[i];
            }
            cnt-=1;
            while(cnt--){
                x1.pop_back();
            }
            cout << x1[1];
            for(int i=2;i<=x1.size()-1;i++){
                cout << ' ' << x1[i];
            }
            cout << endl;
        }
    }

    return 0;
}