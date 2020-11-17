#include <iostream>
#include <string>
using namespace std;

int n,c0,c1,h;
char s[1000+5];

int main(){
    int t;
    cin >> t;
    while(t--){
        int sum = 0;
        cin >> n >> c0 >> c1 >> h;
        string c;
        cin >> c;
        for(int i=0;i<n;i++){
            s[i] = c[i];
        }
        if(c0+c1<h){
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    sum += c0;
                }else{
                    sum += c1;
                }
            }
        }else if(c0+h<c1){
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    sum += c0;
                }else{
                    sum += (c0+h);
                }
            }
        }else if(c1+h<c0){
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    sum += c1;
                }else{
                    sum += (c1+h);
                }
            }
        }else if(c1==c0&&c0==h){
            sum = n*c1;
        }else{
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    sum += c0;
                }else{
                    sum += c1;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}