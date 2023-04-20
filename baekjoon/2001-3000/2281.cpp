#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, k;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  dp.resize(n, vector<ll>(m, INF));
  cin >> k;
  dp[0][k - 1] = 0;
  for(ll i = 1; i < n; i++) {
    cin >> k;
    for(ll j = 0; j < m; j++) {
      // j 이전 단어의 끝 줄
      // 개행하기
      dp[i][k - 1] = min(dp[i][k - 1], dp[i - 1][j] + (m - 1 - j) * (m - 1 - j));

      // 덧붙이기
      if(j + k + 1 < m) {
        dp[i][j + k + 1] = min(dp[i][j + k + 1], dp[i - 1][j]);
      }
    }
  }

  ll answer = INF;
  for(ll i = 0; i < m; i++) {
    answer = min(answer, dp[n - 1][i]);
  }

  cout << answer << '\n';
  

  
  return 0;
}