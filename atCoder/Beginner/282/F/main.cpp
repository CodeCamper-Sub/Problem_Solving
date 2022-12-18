#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, Q, L, R;
vector<pair<ll, ll>> v[15];
ll prefix[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    ll k = 1;
    ll idx = 0;
    while(k <= N) {
        for(ll i = 1; i + k - 1 <= N; i++) {
            v[idx].push_back({i, i + k - 1});
        }
        prefix[idx] = prefix[idx-1] + v[idx].size();
        M += v[idx].size();
        idx++;
        k *= 2;
    }

    cout << M << '\n';
    cout.flush();

    for(ll i = 0; i < idx; i++) {
        for(ll j = 0; j < v[i].size(); j++) {
            cout << v[i][j].first << ' ' << v[i][j].second << '\n';
            cout.flush();
        }
    }

    cin >> Q;
    while(Q--) {
        cin >> L >> R;
        ll length = R - L + 1;
        k = 1;
        idx = 0;
        if(length > 2) {
            while(k < length) {
                idx++;
                k *= 2;
            }
            idx--;
            k /= 2;
        }
        auto left_bound = lower_bound(v[idx].begin(), v[idx].end(), make_pair(L, L + k - 1));
        auto right_bound = lower_bound(v[idx].begin(), v[idx].end(), make_pair(R - k + 1, R));
        ll a = left_bound - v[idx].begin() + prefix[idx-1] + 1;
        ll b = right_bound - v[idx].begin() + prefix[idx-1] + 1;
        cout << a << ' ' << b << '\n';
        cout.flush();
    }

    return 0;
}