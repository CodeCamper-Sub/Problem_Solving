#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, p, u;
vector<ll> a;
vector<vector<ll>> intervals;

void init() {
  cin >> n >> m;
  a.resize(n);
  intervals.assign(n + m + 1, vector<ll>());
  for(ll& a: a) {
    cin >> a;
    intervals[a].push_back(0);
  }
}

void solve() {
  for(ll i = 1; i <= m; i++) {
    cin >> p >> u;
    intervals[u].push_back(i);
    intervals[a[p - 1]].push_back(i);
    a[p - 1] = u;
  }
  
  for(ll i = 0; i < n + m + 1; i++) {
    if(intervals[i].size() % 2) intervals[i].push_back(m + 1);
  }
  ll answer = 0;
  for(ll i = 0; i < n + m + 1; i++) {
    ll cnt = 0;
    for(ll j = 0; j < intervals[i].size(); j += 2) {
      cnt += intervals[i][j + 1] - intervals[i][j];
    }
    answer += (m * (m + 1) / 2) - (m - cnt + 1) * (m - cnt) / 2;
  }

  cout << answer << '\n';

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}