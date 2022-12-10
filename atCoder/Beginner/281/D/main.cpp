#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, d, sum;
ll arr[110], dp[110][110][110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> d;
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= n; j++) {
            for(ll u = 0; u <= d; u++) {
                dp[i][j][u] = -1;
            }
        }
        dp[i][0][0] = 0;
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= i && j <= k; j++) {
            for(ll u = 0; u < d; u++) {
                dp[i][j][u] = max(dp[i][j][u], dp[i-1][j][u]);
                
                ll prev_u = u - (arr[i] % d);
                prev_u = prev_u < 0 ? prev_u + d : prev_u;
                if(dp[i-1][j-1][prev_u] != -1) {
                    dp[i][j][u] = max(dp[i][j][u], dp[i-1][j-1][prev_u] + arr[i]);
                }
            }
        }
    }

    cout << dp[n][k][0] << '\n';

    return 0;
}