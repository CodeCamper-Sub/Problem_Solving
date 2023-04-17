#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000003
typedef long long ll;
using namespace std;

ll N, K, answer;

ll dp[1010][2][1010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  // 0번째를 무조건 고르는 경우 = 2번째부터 N-2번째까지 연속하지 않게 K-1개를 뽑는 경우의 수
  dp[2][0][0] = 1;
  dp[2][1][1] = 1;
  for(ll i = 3; i <= N-2; i++) {
    dp[i][0][0] = 1;
    for(ll k = 1; k <= K-1; k++) {
      dp[i][0][k] = (dp[i-1][0][k] + dp[i-1][1][k]) % MOD;
      dp[i][1][k] = dp[i-1][0][k-1];
    }
  }

  answer += dp[N-2][0][K-1] + dp[N-2][1][K-1];
  answer %= MOD;

  // 0번째를 안 고르는 경우 = 1번째부터 N-1번째까지 연속하지 않게 K개를 뽑는 경우의 수
  for(ll i = 0; i <= N; i++) for(ll j = 0; j < 2; j++) for(ll k = 0; k <= K; k++) {
    dp[i][j][k] = 0;
  }

  dp[1][0][0] = 1;
  dp[1][1][1] = 1;
  for(ll i = 2; i <= N-1; i++) {
    dp[i][0][0] = 1;
    for(ll k = 1; k <= K; k++) {
      dp[i][0][k] = (dp[i-1][0][k] + dp[i-1][1][k]) % MOD;
      dp[i][1][k] = dp[i-1][0][k-1];
    }
  }

  answer += dp[N-1][0][K] + dp[N-1][1][K];
  answer %= MOD;

  cout << answer << '\n';
}