#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt;
string _s;
vector<ll> s;
vector<vector<ll>> dp;

void init() {
  s.clear();
  cin >> _s;
  for (char c : _s) {
    if (c == 'R') {
      s.push_back(0);
    } else if (c == 'S') {
      s.push_back(1);
    } else {
      s.push_back(2);
    }
  }
}

void solve() {
  ll answer = INF;
  for (ll t = 0; t < 3; t++) {
    dp.assign(s.size(), vector<ll>(3, INF));
    dp[0][t] = (s[0] == t ? 0 : 1);
    for (ll i = 1; i < s.size(); i++) {
      for (ll j = 0; j < 3; j++) {
        if(i == s.size() - 1 && j == t) continue;
        for (ll k = 0; k < 3; k++) {
          if (j == k)
            continue;
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j == s[i] ? 0 : 1));
        }
      }
    }
    answer = min(answer, dp[s.size() - 1][0]);
    answer = min(answer, dp[s.size() - 1][1]);
    answer = min(answer, dp[s.size() - 1][2]);
  }

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for (ll i = 1; i <= tt; i++) {
    cout << "Case #" << i << ": ";
    init();
    solve();
  }
  return 0;
}