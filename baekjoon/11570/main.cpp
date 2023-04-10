#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> notes;
vector<vector<ll>> dp;  // 상덕이가 마지막으로 i번째 음을 부르고, 희원이가 마지막으로 j번째 음을 불렀을 때 힘든 정도의 최솟값

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  notes.resize(n + 1);
  dp.assign(n + 1, vector<ll>(n + 1, INF));
  for(ll i = 1; i <= n; i++) cin >> notes[i];

  dp[0][0] = 0;
  for(ll i = 1; i <= n; i++) {
    // dp[0~i-2][i-1]과 dp[i-1][0~i-2] 중의 최솟값
    // dp[0][i - 1] -> dp[i][i -1], dp[0][i]
    dp[i][i - 1] = min(dp[i][i - 1], dp[0][i - 1]);
    dp[0][i] = min(dp[0][i], dp[0][i - 1] + abs(notes[i - 1] - notes[i]));

    // dp[i - 1][0] -> dp[i][0], dp[i - 1][i]
    dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(notes[i - 1] - notes[i]));
    dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][0]);
    for(ll j = 1; j <= i - 2; j++) {
      // dp[j][i-1] -> dp[i][i-1], dp[j][i]
      dp[i][i-1] = min(dp[i][i-1], dp[j][i - 1] + abs(notes[j] - notes[i]));
      dp[j][i] = min(dp[j][i], dp[j][i - 1] + abs(notes[i - 1] - notes[i]));

      // dp[i-1][j] -> dp[i][j], dp[i-1][i]
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(notes[i - 1] - notes[i]));
      dp[i - 1][i] = min(dp[i - 1][i], dp[i - 1][j] + abs(notes[j]- notes[i]));
    }
  }

  ll answer = INF;
  for(ll i = 0; i <= n; i++) {
    answer = min(answer, min(dp[i][n], dp[n][i]));
  }

  cout << answer << '\n';

  return 0;
}