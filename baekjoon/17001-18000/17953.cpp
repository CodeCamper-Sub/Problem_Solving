#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<vector<ll>> dp;
vector<vector<ll>> sat;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  dp.assign(m, vector<ll>(n + 1));
  sat.assign(m, vector<ll>(n + 1));
  
  for(ll i = 0; i < m; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> sat[i][j];
    }
  }

  for(ll i = 0; i < m; i++) dp[i][0] = sat[i][0];

  for(ll j = 1; j < n; j++) {
    for(ll i = 0; i < m; i++) {
      for(ll k = 0; k < m; k++) {
        if(i == k) {
          dp[i][j] = max(dp[i][j], dp[k][j - 1] + sat[i][j] / 2);
        } else {
          dp[i][j] = max(dp[i][j], dp[k][j - 1] + sat[i][j]);
        }
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < m; i++) answer = max(answer, dp[i][n - 1]);

  cout << answer << '\n';

  
  return 0;
}