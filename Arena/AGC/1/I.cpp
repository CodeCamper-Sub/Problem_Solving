#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m;
vector<vector<ll>> grid;
vector<ll> r, c;
map<ll, ll> cnt, c_cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  for(ll j = 0; j < m; j++) {
    for(ll i = 1; i < n; i++) {
      if(grid[i][j] - grid[0][j] != grid[i][0] - grid[0][0]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  r.assign(n, 0);
  cnt[0]++;
  for(ll i = 1; i < n; i++) {
    r[i] = grid[i][0] - grid[0][0];
    cnt[r[i]]++;
  }

  c.assign(m, 0);
  c_cnt[0]++;
  for(ll j = 1; j < m; j++) {
    c[j] = grid[0][j] - grid[0][0];
    c_cnt[c[j]]++;
  }

  ll answer = 0, maxi = 0;
  for(auto [key, value]: cnt) {
    // r[0] = -key
    ll number_of_zero = value;
    for(ll j = 0; j < m; j++) {
      ll c = grid[0][j] + key;
      if(c == 0) number_of_zero++;
    }
    if(maxi < number_of_zero) {
      maxi = number_of_zero;
      answer = key;
    }
  }

  ll c_answer = 0, c_maxi = 0;
  for(auto [key, value]: c_cnt) {
    ll number_of_zero = value;
    for(ll i = 0; i < n; i++) {
      ll r = grid[i][0] + key;
      if(r == 0) number_of_zero++;
    }
    if(c_maxi < number_of_zero) {
      c_maxi = number_of_zero;
      c_answer = key;
    }
  }

  if(maxi >= c_maxi) {
    cout << (n + m - maxi) << '\n';
    for(ll i = 0; i < n; i++) {
      if(r[i] - answer == 0) continue;
      cout << 1 << ' ' << i + 1 << ' ' << r[i] - answer << '\n';
    }
    for(ll j = 0; j < m; j++) {
      if(grid[0][j] + answer == 0) continue;
      cout << 2 << ' ' << j + 1 << ' ' << grid[0][j] + answer << '\n';
    }
  } else {
    cout << (n + m - c_maxi) << '\n';
    for(ll i = 0; i < n; i++) {
      if(grid[i][0] + c_answer == 0) continue;
      cout << 1 << ' ' << i + 1 << ' ' << grid[i][0] + c_answer << '\n';
    }
    for(ll j = 0; j < m; j++) {
      if(c[j] - c_answer == 0) continue;
      cout << 2 << ' ' << j + 1 << ' ' << c[j] - c_answer << '\n';
    }
  }

  return 0;
}