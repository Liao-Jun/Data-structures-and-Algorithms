#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e5+10;

int h[M];
int n, maxH = 0;

bool judge(int x) {
    for (int i = 1; i <= n; i ++ ) {
        x += (x - h[i]);
        if (x >= maxH) return true;
        if (x < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> h[i];
        maxH = max(maxH, h[i]);
    }
    int l = 0, r = maxH;
    while (l < r) {
        int mid = l + r >> 1;
        if (judge(mid)) r = mid;
        else l = mid + 1; 
    }
    cout << l << endl;
    
    return 0;
}