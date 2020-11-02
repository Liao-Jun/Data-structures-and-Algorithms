#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node{
    int x;
    Node *left = NULL, *right = NULL;
};
vector<int> p1,p2;
long long int M = 1e+9;
int result = 0;

Node *CreatTree(int i1, int i2, int j1, int j2){
    if(i1>=i2||j1>=j2) return NULL;
    Node *root = new Node;
    root->x = p2[j2-1];
    int r = p2[j2-1];
    int y = find(p1.begin()+i1, p1.end()+i2, r) - p1.begin();
    root->left = CreatTree(i1, y, j1, j1+(y-i1));
    root->right = CreatTree(y+1, i2, j1+y-i1, j2-1);
    return root;
}

void dfs(Node *root, int sum){
    sum += root->x;
    if(root->left==NULL&&root->right==NULL){
        if(sum<M||sum==M&&root->x<result){
            M = sum;
            result = root->x;
        }
        return;
    }
    if(root->left!=NULL)dfs(root->left, sum);
    if(root->right!=NULL)dfs(root->right, sum);
}

int main(){
    string s1,s2,st;
    while(getline(cin, s1)&&getline(cin, s2)){
        stringstream input1(s1), input2(s2);
        while(input1 >> st){
            p1.push_back(stoi(st));
        }
        while(input2 >> st){
            p2.push_back(stoi(st));
        }
        Node *root = CreatTree(0, p1.size(), 0, p2.size());
        dfs(root, 0);
        cout << result << endl;
        M = 1e+9;
        root = NULL;
        result = 0;
        s1.clear();
        s2.clear();
        st.clear();
        p1.clear();
        p2.clear();
    }

    return 0;
}

//https://vjudge.net/problem/UVA-548