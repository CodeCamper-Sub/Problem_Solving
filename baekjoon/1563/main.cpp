#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000
typedef long long ll;
using namespace std;

ll N, dp[1010][2][3], answer; // 날짜, 지각 횟수, 결석 횟수

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  dp[0][0][0] = 1;
  for(ll i = 0; i < N; i++) {
    // 1. O가 붙는 경우
    for(ll j = 0; j < 2; j++) {
      for(ll k = 0; k < 3; k++) {
        dp[i + 1][j][0] += dp[i][j][k];
        dp[i + 1][j][0] %= MOD;
      }
    }
    // 2. L이 붙는 경우
    for(ll j = 1; j < 2; j++) {
      for(ll k = 0; k < 3; k++) {
        dp[i + 1][j][0] += dp[i][j-1][k];
        dp[i + 1][j][0] %= MOD;
      }
    }
    // 3. K가 붙는 경우
    for(ll j = 0; j < 2; j++) {
      for(ll k = 1; k < 3; k++) {
        dp[i + 1][j][k] += dp[i][j][k-1];
        dp[i + 1][j][k] %= MOD;
      }
    }
  }

  for(ll j = 0; j < 3; j++) for(ll k = 0; k < 3; k++) {
    answer += dp[N][j][k];
    answer %= MOD;
  }

  cout << answer << '\n';

  return 0;
}