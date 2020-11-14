#include <iostream>
using namespace std;

int head[10],nt[10];
int s[10];

int Hush(int u){
	return u;
}

int try_1(int x){
	int h = Hush(s[x]);
	int u = head[h];
	cout << h << ' ' << u << "??";
	while(u){
		if(s[u]==s[x]){
			return 0;
		}
		u = nt[u];
	}
	nt[x] = head[h];
	head[h] = x;
	cout << nt[x] << ' ' << head[h] << ' ';
	return 1;
}

int main(){
	for(int i=0;i<9;i++){
		s[i] = i*i;
	}
	s[9] = 64;
	for(int i=0;i<10;i++){
		cout << i << ' ' << try_1(i) << endl;
	}
	return 0;
}