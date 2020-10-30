#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string s;
    s.clear();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        int r = 1;
        int m = s.length();
        while(1){
            int sum = 0;
            for(int j=0;j<m;j++){
                if(s[j]==s[(j+r)%m]){
                    sum++;
                }else{
                    break;
                }
            }
            if(sum==m){
                break;
            }else{
                r++;
            }
        }
        if(i==0){
            cout << r << endl;
        }else{
            cout << endl << r << endl;
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-455