#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 1'000'000
typedef long long ll;
using namespace std;

ll n;
vector<vector<vector<ll>>> dp;  // dp[i][j][k] i번쨰 사람을 줄 세울 때 남은 줄 세울 사람이 위로 j명 있고, 이전에 k(2: init, 1: 증가, 0: 감소) 했을 때의 경우의 수

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  dp.resize(n);
  for_each(dp.begin(), dp.end(), [](auto& layer){ 
    layer.assign(n + 1, vector<ll>(n + 1, 0));
  });

  for(ll i = 1; i <= n; i++) {
    dp[0][n - i][2] = 1;
    for(ll t = 0; t <= n - i - 1; t++) {
      dp[1][t][1] += dp[0][n - i][2];
      dp[1][t][1] %= MOD;
    }
    for(ll t = n - i; t <= n - 2; t++) {
      dp[1][t][0] += dp[0][n - i][2];
      dp[1][t][0] %= MOD;
    }
  }

  for(ll i = 1; i < n - 1; i++) {
    // 현재까지 줄 세운 사람이 i + 1명
    // 줄 세울 남은 사람은 n - i - 1명
    for(ll j = 0; j <= n - i - 1; j++) {
      // 현재 i보다 큰 사람이 j명
      // 증가하기
      for(ll t = 0; t <= j - 1; t++) {
        dp[i + 1][t][1] += dp[i][j][0];
        dp[i + 1][t][1] %= MOD;
      }
      for(ll t = j; t <= n - i - 2; t++) {
        dp[i + 1][t][0] += dp[i][j][1];
        dp[i + 1][t][0] %= MOD;
      }
    }
  }

  cout << (dp[n - 1][0][0] + dp[n - 1][0][1]) % MOD << '\n';

  return 0;
}