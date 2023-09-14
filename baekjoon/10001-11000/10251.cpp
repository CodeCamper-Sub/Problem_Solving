#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll m, n, l, g;
vector<vector<vector<vector<ll>>>> dp;
vector<vector<ll>> dist_right, dist_down;

void init() {
  cin >> n >> m >> l >> g;
  dp.resize(n);
  for_each(dp.begin(), dp.end(), [](auto &cube) {
    cube.resize(m);
    for_each(cube.begin(), cube.end(), [](auto &layer) {
      layer.assign(min(m, n) * 2, vector<ll>(2, INF));
    });
  });

  dist_right.assign(n, vector<ll>(m, 0));
  dist_down.assign(n, vector<ll>(m, 0));

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m - 1; j++) {
      cin >> dist_right[i][j];
    }
  }

  for (ll i = 0; i < n - 1; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> dist_down[i][j];
    }
  }
}

void solve() {
  dp[0][0][0][0] = 0;
  dp[0][0][0][1] = 0;
  for (ll i = 1; i < n; i++) {
    dp[i][0][0][0] = dp[i - 1][0][0][0] + dist_down[i - 1][0];
  }
  for (ll i = 1; i < m; i++) {
    dp[0][i][0][1] = dp[0][i - 1][0][1] + dist_right[0][i - 1];
  }
  for (ll i = 1; i < n; i++) {
    for (ll j = 1; j < m; j++) {
      for (ll k = 0; k < min(m, n) * 2; k++) {
        if (k > 0) {
          dp[i][j][k][0] = min(dp[i - 1][j][k - 1][1], dp[i - 1][j][k][0]) +
                           dist_down[i - 1][j];

          dp[i][j][k][1] = min(dp[i][j - 1][k - 1][0], dp[i][j - 1][k][1]) +
                           dist_right[i][j - 1];
        } else {
          dp[i][j][k][0] = dp[i - 1][j][k][0] + dist_down[i - 1][j];
          dp[i][j][k][1] = dp[i][j - 1][k][1] + dist_right[i][j - 1];
        }
        if (dp[i][j][k][0] >= INF)
          dp[i][j][k][0] = INF;
        if (dp[i][j][k][1] >= INF)
          dp[i][j][k][1] = INF;
      }
    }
  }

  for(ll k = 0; k < min(m, n) * 2; k++) {
    ll partial_answer = min(dp[n - 1][m - 1][k][0], dp[n - 1][m - 1][k][1]);
    if(partial_answer <= g) {
      ll answer = (m + n - 2) * l + k;
      cout << answer << '\n';
      return;
    }
  }

  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for (ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}