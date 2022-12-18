#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
string s[40];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll answer = 0;
    ll is_solvable = true;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            ll is_solvable = true;
            for(ll k = 0; k < m; k++) {
                if(s[i][k] == 'x' && s[j][k] == 'x') {
                    is_solvable = false;
                }
            }
            if(is_solvable) answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}