#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<pair<ll, ll>> v;
vector<vector<ll>> grid;

void init() {
  cin >> n >> m;
  v.resize(m);
  grid.assign(n + 1, vector<ll>(n + 1, 0));
  for(ll i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
    for(ll j = 1; j <= n; j++) {
      grid[v[i].first][j] = 1;
      grid[j][v[i].second] = 1;
    }
  }
}

void solve() {
  for(auto [x, y]: v) {
    grid[x][y] = 2;
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(grid[i][j] == 0) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
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