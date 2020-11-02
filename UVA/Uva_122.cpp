#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    bool isInput = false;
    int x;
    Node *left = NULL, *right = NULL;
};

Node *Root = NULL;
int flag = 1;

void InsertTree(string s, Node *root){
    int i = s.find(',');
    int x=stoi(s.substr(1,i));
    i++;
    int j = s.find(')');
    if(s[i]==')'){
        if(root->isInput == true){
            flag = -1;
        }
        root->x = x;
        root->isInput = true;
    }else{
        Node *p = root;
        for(i;s[i]!=')';i++){
            if(s[i]=='L'){
                if(p->left==NULL){
                    p->left = new Node;
                }
                p = p->left;
                if(i==j-1){
                    if(p->isInput == true){
                        flag = -1;
                    }
                    p->x = x;
                    p->isInput = true;
                }
            }else if(s[i]=='R'){
                if(p->right==NULL){
                    p->right = new Node;
                }
                p = p->right;
                if(i==j-1){
                    if(p->isInput == true){
                        flag = -1;
                    }
                    p->x = x;
                    p->isInput = true;
                }
            }
        }
    }
}

void OutputTree(Node *root){
    queue<Node*> q;
    vector<int> out;
    int sum = 0;
    if(root!=NULL) q.push(root);
    while(!q.empty()){
        if(q.front()->isInput==false||flag == -1){
            flag = -1;
            break;
        }
        if(q.front()->left!=NULL||q.front()->right!=NULL){
            out.push_back(q.front()->x);
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }else{
            out.push_back(q.front()->x);
            q.pop();
        }
    }
    if(flag==-1){
        cout << "not complete\n";
        flag = 1;
    }else{
        for(int i=0;i<out.size()-1;i++){
            cout << out[i] << ' ';
        }
        cout << out[out.size()-1] << endl;
    }
}

int main(){
    string s;
    while(cin >> s){
        if(s == "()"){
            OutputTree(Root);
            Root = NULL;
        }else{
            if(Root == NULL) Root = new Node;
            InsertTree(s, Root);
        }
    }

    return 0;
}

//https://vjudge.net/problem/UVA-122