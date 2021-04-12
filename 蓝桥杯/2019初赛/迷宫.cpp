#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct node{
    int x, y;
    string s;
    node(){}
    node (int _x, int _y, string _s):x(_x), y(_y), s(_s){}
};
int dic[][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
string dic_char[] = {"D", "L", "R", "U"};

string s[35];
int used[60][60];

string bfs(){
    queue<node> q;
    q.push(node(0, 0, ""));
    used[0][0] = 1;
    while(!q.empty()) {
        node N = q.front();
        q.pop();
        if (N.x == 29 && N.y == 49) return N.s;
        for (int i = 0; i < 4; i ++ ) {
            int x = N.x + dic[i][0];
            int y = N.y + dic[i][1];
            if (x >= 0 && x < 30 && y >= 0 && y < 50 && used[x][y] == 0 && s[x][y] == '0') {
                used[x][y] = 1;
                node n1;
                n1.x = x;
                n1.y = y;
                n1.s = N.s + dic_char[i];
                q.push(n1);
            } 
        }
    }
}

int main() {
    for (int i = 0; i < 30; i ++ ) cin >> s[i];
    memset(used, 0, sizeof(used));
    // cout << bfs() << endl;
    cout << "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR" << endl;

    return 0;
} 