#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        ll n, m, d;
        cin >> n >> m >> d;
        vector<ll> p(n), a(m);
        vector<ll> pos;
        for(ll i = 0; i < n; i++) {
            cin >> p[i];
        }
        for(ll i = 0; i < m; i++) {
            cin >> a[i];
        }
        ll j = 0;
        for(ll i = 0; i < n && j < m; i++) {
            if(p[i] == a[j]) {
                pos.push_back(i);
                j++;
            }
        }
        if(pos.size() != m) {
            cout << 0 << '\n';
            continue;
        }
        ll answer = INF;
        for(ll i = 0; i < pos.size() - 1; i++) {
            answer = min(answer, pos[i+1] - pos[i]);
            if(n > d + 1) {
                answer = min(answer, d - (pos[i+1] - pos[i]) + 1);
            }
        }
        answer = max(answer, 0ll);
        cout << answer << '\n';
    }
    return 0;
}