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
        ll n, grid[1010][1010];
        ll answer = 0;
        cin >> n;
        for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
            cin >> grid[i][j];
            answer ^= grid[i][j];
        }
        for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
            ll dx[4] = {0, 0, 1, -1};
            ll dy[4] = {1, -1, 0, 0};
            for(ll k = 0; k < 4; k++) {
                ll ny = i + dy[k];
                ll nx = j + dx[k];
                if(ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    answer ^= grid[i][j];
                }
            }
        }
        cout << "Answer (Case #" << tt << "):";
        cout << answer << '\n';
    }
    return 0;
}