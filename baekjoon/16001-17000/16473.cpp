#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<ll> arr;
vector<vector<ll>> dp;

void init() {
  
}

ll solve(ll l, ll r) {
  if(l < 0 || r >= n) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  ll& ret = dp[l][r] = 0;
  
  if(arr[l] == arr[r]) {
    ret = solve(l - 1, r + 1) + (l != r ? 2 : 1);
  } else {
    ret = max(solve(l - 1, r), solve(l, r + 1));
  }

  return ret;
}

void solve() {
  ll m;
  cin >> m;
  m--;

  cout << n - solve(m, m) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  arr.resize(n);
  dp.assign(n, vector<ll>(n, -1));
  for(ll& a: arr) cin >> a;
  ll tt;
  cin >> tt;

  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}