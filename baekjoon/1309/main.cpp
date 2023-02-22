#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 9901
typedef long long ll;
using namespace std;

ll N, dp[100100][(1 << 2)];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;
  for(ll i = 1; i < N; i++) {
    dp[i + 1][0] = dp[i][0] + dp[i][1] + dp[i][2];
    dp[i + 1][0] %= MOD;
    dp[i + 1][1] = dp[i][0] + dp[i][2];
    dp[i + 1][1] %= MOD;
    dp[i + 1][2] = dp[i][0] + dp[i][1];
    dp[i + 1][2] %= MOD;
  }
  cout << (dp[N][0] + dp[N][1] + dp[N][2]) % MOD << '\n';

  return 0;
}