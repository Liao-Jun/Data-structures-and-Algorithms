#include <iostream>
#include <stdio.h>
using namespace std;

char x[7][7];
int x11;
int y11;
char s;

bool Judge(char s, int k, int l){
    if(s=='A'){
        k = k-1;
    }else if(s=='B'){
        k = k+1;
    }else if(s=='L'){
        l = l-1;
    }else if(s=='R'){
        l = l+1;
    }

    if(k<0||k>=5||l<0||l>=5){
        return false;
    }
    return true;
}

void Go(char s, int &k, int &l){
    if(s=='A'){
        x[k][l] = x[k-1][l];
        x[k-1][l] = ' ';
        k = k-1;
    }else if(s=='B'){
        x[k][l] = x[k+1][l];
        x[k+1][l] = ' ';
        k = k+1;
    }else if(s=='L'){
        x[k][l] = x[k][l-1];
        x[k][l-1] = ' ';
        l = l-1;
    }else if(s=='R'){
        x[k][l] = x[k][l+1];
        x[k][l+1] = ' ';
        l = l+1;
    }
}

int main(){
    int flag = 0;
    while((x[0][0] = getchar())&&x[0][0]!='Z'){
        x11 = 0;
        y11 = 0;
        int m = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==0&&j==0)continue;
                x[i][j] = getchar();
                if(x[i][4]=='\n') x[i][4] = ' ';
                if(x[i][j]==' '){
                    x11 = i;
                    y11 = j;
                }
            }
            getchar();
        }
        while((s = getchar())&&s!='0'){
            if(m==1){
                continue;
            }
            if(s>='A'&&s<='R'){
                if(Judge(s,x11,y11)){
                    Go(s,x11,y11);
                }else{
                    m = 1;
                }
            }
        }
        getchar();
        if(flag!=0){
            cout << endl;
        }
        flag++;
        cout << "Puzzle #" << flag << ':' << endl;
        if(m==1){
            cout << "This puzzle has no final configuration." << endl;
            m = 0;
        }else{
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
					if(j != 0) cout << ' ';
					printf("%c",x[i][j]);
                }
                cout << endl;
            }
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-227#author=0