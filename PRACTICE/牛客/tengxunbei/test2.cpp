#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> dic = {{'S',1},{'J',2},{'B',3}};

int main(){
    char a;
    string s;
    cin >> s >> a;
    int p[2] = {dic[s[0]],dic[s[1]]};
    int l = dic[a];
    int flag = 0;
    for(int i=0;i<2;i++){
        if(p[i]-l==-1||(p[i]==3&&l==1)){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout << "pmznb" << endl;
    }else{
        cout << "lyrnb" << endl;
    }

    return 0;
}