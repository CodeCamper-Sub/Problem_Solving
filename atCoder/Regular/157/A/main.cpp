#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b >> c >> d;

    if(n == 1) {
        cout << "Yes\n";
        return 0;
    }

    if(b == 0 && c == 0) {
        if(a > 0 && d > 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
        return 0;
    }

    if(abs(b - c) >= 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }


    return 0;
}