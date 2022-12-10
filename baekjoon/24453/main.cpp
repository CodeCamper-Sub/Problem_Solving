#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, x, y, minimum;
ll err;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    minimum = INF;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        cin >> err;
        v.push_back(err);
    }
    cin >> x >> y;

    sort(v.begin(), v.end());
    for(ll i = 0; i < v.size(); i++) {
        if(i == 0) {
            auto iter = upper_bound(v.begin(), v.end(), x);
            ll erased_errors = iter - v.begin() - i;
            minimum = min(minimum, erased_errors);
        } else if (v[i-1] + x <= n) {
            auto iter = upper_bound(v.begin(), v.end(), v[i-1]+x);
            ll erased_errors = iter - v.begin() - i;
            minimum = min(minimum, erased_errors);
        }
    }

    if(minimum < y) {
        cout << m - y << '\n';
    } else {
        cout << m - minimum << '\n';
    }


    return 0;
}