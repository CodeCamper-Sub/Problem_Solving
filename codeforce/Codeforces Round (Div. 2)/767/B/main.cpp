#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll tt;
    cin >> tt;
    while(tt--) {
        ll l, r, k;
        cin >> l >> r >> k;
        if(l == r) {
            if(l == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            continue;
        }
        ll number_of_even;
        if(l % 2 == 0) {
            if((r-l+1)%2 == 0) {
                number_of_even = (r-l+1)/2;
            } else {
                number_of_even = (r-l+1)/2 + 1;
            }
        } else {
            number_of_even = (r-l+1)/2;
        }
        if(number_of_even + k >= r - l + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}