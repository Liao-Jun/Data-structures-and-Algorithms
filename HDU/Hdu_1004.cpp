#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

struct boon{
    string color;
    mutable int count;
    boon(string s){
        color = s;
        count = 0;
    }
    void addCount(){
        count++;
    }
};

bool operator==(const struct boon &a, const struct boon &b){
    string x = a.color;
    string y = b.color;
    return std::hash<string> () (x) == std::hash<string> () (y);
}

struct MyHush{
    int operator()(const struct boon &_a)const{
        string x = _a.color;
        return std::hash<string> () (x);
    }
};

int main(){
    ios::sync_with_stdio(false);

    int n;
    while(cin >> n&&n!=0){
        string s;
        unordered_set<boon, MyHush> Boon;
        for(int i=0;i<n;i++){
            
            cin >> s;
            auto x = Boon.insert(boon(s));
            x.first->count += 1;
        }
        int MaxCount = 0;
        string MaxString = "";
        for(auto it=Boon.begin();it!=Boon.end();++it){
            if(it->count>MaxCount){
                MaxCount = it->count;
                MaxString = it->color;
            }
        }
        cout << MaxString << endl;
    }

    return 0;
}