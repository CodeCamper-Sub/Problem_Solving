#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 1001000
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll n, dp[MAX][5];
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;
  dp[0][0] = 1;
  for (ll i = 1; i <= n; i++) {
    if (s[i - 1] == 'R') {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2 + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
      dp[i][4] = dp[i - 1][4];
    } else if (s[i - 1] == 'O') {
      dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
      dp[i][4] = dp[i - 1][4];
    } else if (s[i - 1] == 'C') {
      dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][2] + dp[i - 1][3];
      dp[i][4] = dp[i - 1][4];
    } else if (s[i - 1] == 'K') {
      dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
      dp[i][4] = dp[i - 1][3] + dp[i - 1][4];
    } else {
      dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
      dp[i][4] = dp[i - 1][4];
    }

    for(ll j = 0; j < 5; j++) {
      dp[i][j] %= MOD;
    }
  }

  cout << dp[n][4] << '\n';

  return 0;
}