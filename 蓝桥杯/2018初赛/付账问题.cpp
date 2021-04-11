#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

const int maxn = 5e5+10;

int n;
ll s;
ll a[maxn];

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + n);
    double avg = s*1.0/n;
    double sum = 0.0;
    for (int i = 0; i < n; i ++ ) {
        if (a[i]*(n - i) < s) {
            s -= a[i];
            sum += (a[i] - avg)*(a[i] - avg);
        }else {
            double A = s*1.0/(n - i);
            sum += (A - avg)*(A - avg)*(n - i);
            break;
        }
    }
    printf("%.4f",sqrt(sum/n));

    return 0;
}