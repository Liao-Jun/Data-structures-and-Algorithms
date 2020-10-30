#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> word;
map<string, int> x;

string To(string s){
    int n = s.length();
    string x = s;
    for(int i=0;i<n;i++){
        x[i] = tolower(x[i]);
    }
    sort(x.begin(),x.end());
    return x;
}

int main(){
    string s;
    while(cin >> s){
        if(s[0] == '#'){
            break;
        }
        word.push_back(s);
        s = To(s);
        if(x.count(s)==0){
            x[s] = 0;
        }
        x[s]++;
    }
    vector<string> result;
    for(int i=0;i<word.size();i++){
        if(x[To(word[i])]==1){
            result.push_back(word[i]);
        }
    }
    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-156