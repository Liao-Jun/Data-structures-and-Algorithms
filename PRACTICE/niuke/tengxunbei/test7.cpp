#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int cnt = s.length();
        map<char, int> dic;
        for(int i=0;i<s.length();i++){
            if(dic[s[i]]<1){
                dic[s[i]] = 1;
            }else{
                dic[s[i]]++;
            }
        }
        for(map<char,int>::iterator it=dic.begin();it!=dic.end();++it){
            if(it->second==4){
                cnt ++;
                cnt += 4*13;
                cnt += 6;
            }else if(it->second==3){
                cnt += 4*13;
            }else if(it->second==2){
                cnt ++;
            }
        }
        for(map<char,int>::iterator it=dic.begin();it!=dic.end();++it){
            if(it->second==4){
                for(map<char,int>::iterator it1=dic.begin();it1!=dic.end();++it1){
                    if(it1->first!=it->first){
                        if(it1->second==2){
                            cnt += 4;
                        }else if(it1->second==3){
                            cnt += 12;
                        }else if(it1->second==4){
                            cnt += 24;
                        }
                    }
                }
            }else if(it->second==3){
                for(map<char,int>::iterator it1=dic.begin();it1!=dic.end();++it1){
                    if(it1->first!=it->first){
                        if(it1->second==2){
                            cnt += 1;
                        }else if(it1->second==3){
                            cnt += 3;
                        }else if(it1->second==4){
                            cnt += 6;
                        }
                    }
                }
            }
        }
        int p[20];
        fill(p,p+20,0);
        for(int i=0;i<s.length();i++){
            if(s[i]>='3'&&s[i]<='9'){
                p[s[i]-'3']++;
            }else if(s[i]=='0'){
                p[7]++;
            }else if(s[i]=='J'){
                p[8]++;
            }else if(s[i]=='Q'){
                p[9]++;
            }else if(s[i]=='K'){
                p[10]++;
            }else if(s[i]=='A'){
                p[11]++;
            }else if(s[i]=='2'){
                p[12]++;
            }
        }
        for(int i=0;i<=8;i++){
            if(p[i]>0&&p[i+1]>0&&p[i+2]>0&&p[i+3]>0&&p[i+4]>0){
                cnt += (p[i]*p[i+1]*p[i+2]*p[i+3]*p[i+4]);
            }
        }
        cout << cnt << endl;
    }

    return 0;
}