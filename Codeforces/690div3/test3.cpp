#include <iostream>
#include <vector>
using namespace std;

int dic[] = {9,8,7,6,5,4,3,2,1};

int main(){
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        if(n<=9) cout << n << endl;
        else if(n>45) cout << -1 << endl;
        else{
            vector<int> x;
            int cnt = 0;
            while(n>0){
                if(n<=dic[cnt]){
                    x.push_back(n);
                    n = 0;
                    break;
                }
                n -= dic[cnt];
                x.push_back(dic[cnt]);
                cnt++;
            }
            for(auto it = x.rbegin();it!=x.rend();++it){
                cout << *it;
            }
            cout << endl;
        }
    }

    return 0;
}