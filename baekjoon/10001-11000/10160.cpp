#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 1'000'000'009
typedef long long ll;
using namespace std;

ll n, k;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  dp.assign(7, vector<ll>(n));
  dp[0][0] = k - 1;
  dp[1][0] = 1;

  for(ll i = 1; i < n; i++) {
    dp[0][i] = dp[0][i - 1] * (k - 1) + dp[1][i - 1] * (k - 2) + dp[2][i - 1] * (k - 2) + dp[3][i - 1] * (k - 2) + dp[4][i - 1] * (k - 2) + dp[5][i - 1] * (k - 2) + dp[6][i - 1] * (k - 2);
    dp[0][i] %= MOD;
    dp[1][i] = dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1] + dp[4][i - 1] + dp[6][i - 1];
    dp[1][i] %= MOD;
    dp[2][i] = dp[1][i - 1];
    dp[3][i] = dp[2][i - 1] + dp[5][i - 1];
    dp[3][i] %= MOD;
    dp[4][i] = dp[2][i - 1];
    dp[5][i] = dp[3][i - 1];
    dp[6][i] = dp[4][i - 1];
  }

  ll answer = 0;
  for(ll i = 0; i < 7; i++) {
    answer += dp[i][n - 1];
    answer %= MOD;
  }

  cout << answer << '\n';

  #ifdef LOCAL
  for(ll i = 0; i < 6; i++) {
    for(ll j = 0; j < n; j++) {
      cout.width(7);
      cout << dp[i][j] << ' ';
    }
    cout << '\n';
  }
  #endif
  
  return 0;
}