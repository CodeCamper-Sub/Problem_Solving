#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

double h, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    cin >> h >> w;
    if(h > w) swap(h, w);
    if(w >= h / sqrt(3) * 2) {
        cout << (h / sqrt(3)) * 2 << '\n';
    } else {
        double theta = atan((2 * h / w) - sqrt(3));
        cout << w / cos(theta) << '\n';
    }


    return 0;
}