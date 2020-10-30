#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef set<int> Set;
map<Set, int> IDnumber;
vector<Set> CunID;

int ID(Set x){
    if(IDnumber.count(x)!=0){
        return IDnumber[x];
    }
    CunID.push_back(x);
    IDnumber[x] = CunID.size() - 1;
    return IDnumber[x];
}

int main(){
    int t;
    int l;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> l;
        stack<int> r;
        for(int j=0;j<l;j++){
            string m;
            cin >> m;
            if(m[0]=='P'){
                r.push(ID(Set()));
            }else if(m[0]=='D'){
                r.push(r.top());
            }else{
                Set a = CunID[r.top()];
                r.pop();
                Set b = CunID[r.top()];
                r.pop();
                Set x;
                if(m[0]=='U'){
                    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(x,x.begin()));
                }else if(m[0]=='I'){
                    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(x,x.begin()));
                }else if(m[0]=='A'){
                    x = b;
                    x.insert(ID(a));
                }
                r.push(ID(x));
            }
            cout << CunID[r.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-12096