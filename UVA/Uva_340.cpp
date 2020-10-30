#include <iostream>
using namespace std;

int s[1000];
int s1[1000];
int x[1000];
int x1[1000];
int sum = 0;

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        cout << "Game " << ++sum << ":\n";
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
        }
        while(1){
            int a=0,b=0;
            for(int i=0;i<n;i++){
                scanf("%d",&x[i]);
                s1[i]=0;
                x1[i]=0;
            }
            if(x[0]==0){
                break;
            }
            for(int i=0;i<n;i++){
                if(s[i]==x[i]){
                    a++;
                    s1[i]=1;
                    x1[i]=1;

                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(x1[j]!=1&&s1[i]!=1){
                        if(s[i]==x[j]){
                            b++;
                            x1[j]=1;
                            s1[i]=1;
                        }
                    }
                }
            }
            cout << "    (" << a << ',' << b << ")\n"; 
        }
    }
}

//https://vjudge.net/problem/UVA-340#author=0