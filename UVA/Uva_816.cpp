#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int x,y;
    string dir[4];
    Node(int x1 = 0, int y1 = 0, string a = "", string b = "", string c = "", string d = ""){
        x = x1;
        y = y1;
        dir[0] = a;
        dir[1] = b;
        dir[2] = c;
        dir[3] = d;
    }
};

struct Node1{
    Node x;
    char y = NULL;
    Node1(Node x1, char y1 = NULL){
        x = x1;
        y = y1;
    }
};

struct Node2{
    int x;
    int y;
    Node2(int x1 = 0, int y1 = 0){
        x = x1;
        y = y1;
    }
};

Node Maze[10][10];
string name;
int x,y,x1,y1;
string s;
queue<Node1> q;
vector<Node2> result;
map<char, int> d = {{'N',1},{'S',3},{'E',2},{'W',4}};
map<char, int> t = {{'F',0},{'L',-1},{'R',1}};

void Direction(int &a, int &b, char s){
    if(s=='N'){
        a -= 1;
    }else if(s=='S'){
        a += 1;
    }else if(s=='W'){
        b -= 1;
    }else if(s=='E'){
        b += 1;
    }
}

char Dir(char c1, char c2){
    int l = d[c1] +t[c2];
    for(auto it=d.begin();it!=d.end();++it){
        if(it->second==l){
            return it->first;
        }
    }
}

void bfs(){
    while(!q.empty()){
        Node1 b = q.front();
        cout << '?' << b.x.x << ' ' << b.x.y << ' ' << b.y << '?' << endl;//debug
        q.pop();
        if(b.x.x==x1&&b.x.y==y1){
            result.push_back(Node2(b.x.x, b.x.y));
            int i =0;
            for(auto it=result.begin(); it!=result.end(); ++it,++i){
                if(i%10==0){
                    cout << ' ';
                }
                printf(" (%d,%d)",it->x,it->y);
                if((i+1)%10==0){
                    cout << endl;
                }
            }
            return;
        }
        for(int i=0;i<4;i++){
            cout << "!!!!!!!" << b.x.dir[i][0] << endl;//debug
            if(b.x.dir[i][0]==b.y){
                cout << "!!!!!" << endl;//debug
                for(int j=1;j<b.x.dir[i].length();j++){
                    int x0 = b.x.x;
                    int y0 = b.x.y;
                    result.push_back(Node2(x0, y0));
                    char cc = Dir(b.y, b.x.dir[i][j]);
                    Direction(x0, y0, cc);
                    q.push(Node1(Maze[x0][y0],cc));
                }
            break;
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main(){
    while(cin >> name&&name!="END"){
        int x0,y0,x1,y1;
        cin >> x >> y >> s;
        x0 = x;
        y0 = y;
        char c = s[0];
        Maze[x][y] = Node(x,y,s);
        cin >> x >> y;
        Maze[x][y] = Node(x,y);
        while(cin >> x&&x!=0){
            cin >> y >> s;
            Maze[x][y]  = Node(x,y,s);
            int cnt1 = 1;
            while(cin >> s&&s!="*"){
                Maze[x][y].dir[cnt1++] = s;
            }
        }
        result.push_back(Node2(x0,y0));
        Direction(x0, y0, c);
        q.push(Node1(Maze[x0][y0],c));
        bfs();

    }

    return 0;
}