#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
using namespace std;

using ll = long long;

int dic[] = {3, 5, 7};
map <ll, int> mp;

int main() {
    // ll a = 59084709587505;
    // priority_queue <ll, vector<ll>, greater<ll>> q;
    // int cnt =  -1;
    // q.push(1);
    // while (1) {
    //     ll x = q.top();
    //     cnt ++;
    //     if (x == a) break;
    //     q.pop();
    //     for (int i = 0; i < 3; i ++ ) {
    //         ll y = x*dic[i];
    //         if (mp[y] == 0) {
    //             q.push(y);
    //             mp[y] = 1;
    //         }
    //     }
    // }
    // cout << cnt << endl;
    cout << 1905 << endl;

    return 0;
}