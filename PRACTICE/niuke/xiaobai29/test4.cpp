#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if(n%2) cout << "-1\n";
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int f=i%4<2?0:1;
                    if(j%2)f=!f;
                    if(k%4<2)f=!f;
                    printf("%d ",f);
                }
            printf("\n");
            }
        }
    }

    return 0;
}