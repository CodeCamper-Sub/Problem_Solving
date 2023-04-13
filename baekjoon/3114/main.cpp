#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll r, c;
string s;
vector<vector<ll>> a_grid, b_grid, p_a, p_b, dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c;
  a_grid.assign(r + 1, vector<ll>(c + 1, 0));
  p_a.assign(r + 1, vector<ll>(c + 1, 0));
  b_grid.assign(r + 1, vector<ll>(c + 1, 0));
  p_b.assign(r + 1, vector<ll>(c + 1, 0));
  dp.assign(r + 1, vector<ll>(c + 1, 0));

  for(ll i = 1; i <= r; i++){
    for(ll j = 1; j <= c; j++) {
      cin >> s;
      if(s[0] == 'A') {
        a_grid[i][j] = stoi(s.substr(1));
      } else {
        b_grid[i][j] = stoi(s.substr(1));
      }
    }
  }

  for(ll i = 1; i <= r; i++) {
    for(ll j = 1; j <= c; j++) {
      p_a[i][j] = p_a[i][j - 1] + a_grid[i][j];
      p_b[i][j] = p_b[i - 1][j] + b_grid[i][j];
    }
  }

  for(ll i = 2; i <= r; i++) {
    for(ll j = 2; j <= c; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + p_a[i][j - 1] + p_b[i - 1][j]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + p_a[i][j - 1]);
      dp[i][j] = max(dp[i][j], dp[i][j - 1] + p_b[i - 1][j]);
    }
  }
  
  cout << dp[r][c] << '\n';
  
  return 0;
}