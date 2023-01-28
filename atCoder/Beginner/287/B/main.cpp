#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
string s[1010], t[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(ll i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> t[i];
    }
    ll answer = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(s[i].substr(3).compare(t[j]) == 0) {
                answer++;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}