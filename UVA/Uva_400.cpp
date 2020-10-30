#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100+5, maxL = 60; 
string file[N];
 
void print(const string& s,int len){
	cout<< s;
	for(int i = s.length(); i < len; i++) cout<< " ";
}
 
int main(int argc, char** argv) {
	int n;
	while(cin>> n){
		int maxLength = 0;
		for(int i = 0; i < n; i++){
			cin>> file[i];
			maxLength = max(maxLength, (int)file[i].length());
		}
		sort(file, file+n);
		int column = (maxL - maxLength)/(maxLength+2)+1,  row = (n-1)/column+1;
		for(int i = 0; i < 60; i++) cout<< "-";
		cout<< "\n";
		for(int i = 0; i < row; i++){
			for(int j = 0; j < column; j++){
				int idx = j*row+i;
				if(idx < n)print(file[idx],j == column-1 ? maxLength : maxLength+2);
			}
			cout<< "\n";
		}
	}	
	return 0;
}

//https://vjudge.net/problem/UVA-400#author=Zsc1615925460

