#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int h,w,cnt;
string s[200+5],x[200+5],result;
map<char, string> Change = {{'1',"0001"},{'2',"0010"},{'0',"0000"},{'3',"0011"},{'4',"0100"},{'5',"0101"},
                             {'6',"0110"},{'7',"0111"},{'8',"1000"},{'9',"1001"},{'a',"1010"},{'b',"1011"},
                             {'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}};
map<int, char> dic = {{1,'A'},{3,'J'},{5,'D'},{4,'S'},{0,'W'},{2,'K'}};
int d[4][2] = {{1,0},{-1,0},{0,1},{0-1}};

void dfs(int x1, int y1){
    x[x1][y1] = '4';
    for(int i=0;i<4;i++){
        int x2 = x1+d[i][0];
        int y2 = y1+d[i][1];
        if(x2>=0&&x2<h+2&&y2>=0&&y2<x[0].length()&&x[x2][y2]=='0'){
            dfs(x2,y2);
        }
    }
}

void dfs2(int x1, int y1,char ch){
    x[x1][y1] = char(ch+2);
    for(int i=0;i<4;i++){
        int x2 = x1+d[i][0];
        int y2 = y1+d[i][1];
        if(x2>=0&&x2<h+2&&y2>=0&&y2<x[0].length()){
            if(ch=='1'&&x[x2][y2]=='0'){
                cnt ++;
                dfs2(x2,y2,'0');
            }
            if(ch==x[x2][y2]){
                dfs2(x2,y2,ch);
            }
        }
    }
}

int main(){
    while(cin>>h>>w&&h!=0&&w!=0){
        cnt = 0;
        result.clear();
        for(int i=0;i<h+2;i++){
            x[i].clear();
            x[i] = '0';
            if(i==0||i==h+1){
                for(int j=0;j<w*4+1;j++){
                    x[i] += '0';
                }
                continue;
            }
            cin >> s[i];
            for(int j=0;j<w;j++){
                x[i] += Change[s[i][j]];
            }
            x[i] += '0';
        }
        for(int i=0;i<h+2;i++){
            for(int j=0;j<x[0].length();j++){
                cout << x[i][j] << ' ';
            }
            cout <<endl;
        }
        cout <<endl;
        dfs(0,0);
        for(int i=0;i<h+2;i++){
            for(int j=0;j<x[0].length();j++){
                cout << x[i][j] << ' ';
            }
            cout <<endl;
        }
        for(int i=0;i<h+2;i++){
            for(int j=0;j<x[0].length();j++){
                if(x[i][j]=='1'){
                    dfs2(i,j,'1');
                    result += dic[cnt];
                    cnt = 0;
                }
            }
        }
        sort(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}
