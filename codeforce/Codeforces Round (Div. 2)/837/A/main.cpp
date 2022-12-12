#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, a, minimum, maximum, minimum_cnt, maximum_cnt;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        cin >> n;
        minimum = INF;
        minimum_cnt = 0;
        maximum = -INF;
        maximum_cnt = 0;
        v = vector<ll>();
        for(ll i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
            minimum = min(minimum, a);
            maximum = max(maximum, a);
        }
        for(ll i = 0; i < n; i++) {
            if(v[i] == minimum) minimum_cnt++;
            if(v[i] == maximum) maximum_cnt++;
        }
        if(minimum != maximum) {
            cout << minimum_cnt * maximum_cnt * 2 << '\n';
        } else {
            cout << maximum_cnt * (maximum_cnt - 1) << '\n';
        }
    }

    return 0;
}