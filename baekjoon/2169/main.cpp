#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
ll grid[1010][1010], dp[1010][1010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) {
    cin >> grid[i][j];
  }

  dp[1][1] = grid[1][1];
  for(ll i = 2; i <= m; i++) {
    dp[1][i] = grid[1][i] + dp[1][i - 1];
  }
  for(ll i = 2; i <= n; i++) {
    // 오른쪽으로 진행
    ll right[1010];
    fill(right, right + m + 1, -INF);
    right[1] = dp[i-1][1] + grid[i][1];
    for(ll j = 2; j <= m; j++) {
      right[j] = max(right[j-1], dp[i-1][j]) + grid[i][j];
    }

    // 왼쪽으로 진행
    ll left[1010];
    fill(left, left + m + 1, -INF);
    left[m] = dp[i-1][m] + grid[i][m];
    for(ll j = m - 1; j >= 1; j--) {
      left[j] = max(left[j + 1], dp[i-1][j]) + grid[i][j];
    }

    for(ll j = 1; j <= m; j++) {
      dp[i][j] = max(left[j], right[j]);
    }
  }

  cout << dp[n][m] << '\n';
  
  return 0;
}