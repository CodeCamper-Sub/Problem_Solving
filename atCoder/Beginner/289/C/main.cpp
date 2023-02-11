#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, c, a;
set<ll> s[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        cin >> c;
        for(ll j = 0; j < c; j++) {
            cin >> a;
            s[i].insert(a);
        }
    }

    ll answer = 0;
    for(ll i = 0; i < (1 << m); i++) {
        set<ll> visited;
        for(ll j = 0; j < m; j++) {
            if(i & (1 << j)) {
                for(ll k: s[j]) {
                    visited.insert(k);
                }
            }
        }
        if(visited.size() == n) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}