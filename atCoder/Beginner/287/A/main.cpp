#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    k = 0;
    cin >> n;

    for(ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "For") {
            k++;
        }
    }

    if(k > n / 2) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}