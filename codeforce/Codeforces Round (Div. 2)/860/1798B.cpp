#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, n, maxi;
vector<ll> visited, answer;
vector<vector<ll>> p;

void init() {
  cin >> m;
  p.assign(m, vector<ll>());
  maxi = -INF;
  for(ll i = 0; i < m; i++) {
    cin >> n;
    p[i].resize(n);
    for(ll j = 0; j < n; j++) {
      cin >> p[i][j];
    }
    maxi = max(maxi, *max_element(p[i].begin(), p[i].end()));
  }
}

void solve() {
  visited.assign(maxi + 1, false);
  answer.clear();

  for(ll i = m - 1; i >= 0; i--) {
    bool is_valid = false;
    for(ll j = 0; j < p[i].size(); j++) {
      if(!visited[p[i][j]] && !is_valid) {
        answer.push_back(p[i][j]);
        is_valid = true;
      }
      visited[p[i][j]] = true;
    }
    if(!is_valid) {
      cout << "-1\n";
      return;
    }
  }
  while(answer.size()) {
    cout << answer.back() << ' ';
    answer.pop_back();
  }
  cout << '\n';
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