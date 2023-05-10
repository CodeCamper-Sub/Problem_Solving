#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
vector<vector<ll>> grid;

void init() {
  cin >> n;
  a.clear();
  grid.assign(n, vector<ll>(n));
}

void solve() {
  ll k = 1;
  a.push_back(n * n);
  while(a.size() < n * n) {
    a.push_back(k);
    if(n * n - k != k) {
      a.push_back(n * n - k);
    }
    k++;
  }
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      ll now = i * n + j;
      if(i % 2) {
        grid[i][j] = a[now];
      } else {
        grid[i][n - 1 - j] = a[now];
      }
    }
  }
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
    cout << grid[i][j] << " \n"[j == n - 1];
  }
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