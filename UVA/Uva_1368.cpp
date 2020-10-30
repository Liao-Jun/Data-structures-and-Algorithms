#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[55];
string x;
int sum[5][1005];

struct _type{
    int x;
    char y;
};

bool _cmp(const _type &a, const _type &b){
    if(a.x==b.x){
        return a.y > b.y;
    }
    return a.x < b.x;
}

int main(){
    int t;
    int n,m;
    cin >> t;

    for(int i=0;i<t;i++){
        cin >> m >> n;
        int Sum = 0;
        for(int j=0;j<4;j++){
            for(int k=0;k<n;k++){
                sum[j][k] = 0;
            }
        }
        for(int j=0;j<m;j++){
            cin >> s[j];
            int l = s[j].length();
            for(int k=0;k<l;k++){
                if(s[j][k]=='A'){
                    sum[0][k]++;
                }else if(s[j][k]=='C'){
                    sum[1][k]++;
                }else if(s[j][k]=='G'){
                    sum[2][k]++;
                }else if(s[j][k]=='T'){
                    sum[3][k]++;
                }
            }
        }
        for(int j=0;j<n;j++){
            _type a[5];
            for(int i=0;i<4;i++){
                a[i].x = sum[i][j];
            }
            a[0].y = 'A';
            a[1].y = 'C';
            a[2].y = 'G';
            a[3].y = 'T';
            sort(a,a+4,_cmp);            
            Sum += a[0].x+a[1].x+a[2].x;
            cout << a[3].y;

        }
        cout << endl << Sum << endl;
    }

    return 0;
}

//https://vjudge.net/problem/UVA-1368