#include <iostream>
#include <algorithm>

using namespace std;


int w, m, n;
int main() {
    cin >> w >> m >> n;
    m --;
    n --;
    int M = m%w;
    int N = n%w;
    int a = abs(m/w - n/w);
    if(m/w%2 == 1) M = w - 1 - M;
    if(n/w%2 == 1) N = w - 1 - N;
    cout << a + abs(M - N) << endl;

    return 0;
}