#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<bool> valid;
vector<vector<char>> grid;

void init() {
  cin >> n >> k;
  grid.assign(n, vector<char>(k));
  valid.assign(n, true);
  for(ll i = 0; i < n; i++) for(ll j = 0; j < k; j++) cin >> grid[i][j];
}

void solve() {
  for(ll j = 0; j < k; j++) {
    for(ll i = 0; i < n; i++) {
      if(grid[0][j] != grid[i][j]) {
        valid[i] = false;
      }
    }
  }
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    if(valid[i]) answer++;
  }
  cout << answer << '\n';
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