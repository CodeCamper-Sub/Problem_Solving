#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n;
ll a[200200];
bool is_impossible;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if ( a[n-1] > a[n] ) {
            cout << -1 << '\n';
        }
        else if ( a[n] < 0 ) {
            is_impossible = false;
            for (int i = 2; i <= n; i++) {
                if (a[i - 1] > a[i]) {
                    is_impossible = true;
                    break;
                }
            }
            if (is_impossible) {
                cout << -1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else {
            cout << n-2 << '\n';
            for (int i = n-2; i >= 1; i--) {
                cout << i << ' ' << i+1 << ' ' << n << '\n';
            }
        }
    }
    return 0;
}