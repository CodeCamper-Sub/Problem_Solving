#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> v, psum, dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  v.resize(n + 1);
  psum.assign(n + 1, 0);
  dp.assign(n + 1, -INF);
  for(ll i = 1; i <= n; i++) {
    cin >> v[i];
    psum[i] = psum[i - 1] + v[i];
  }
  dp[m] = psum[m];
  for(ll i = m + 1; i <= n; i++) {
    dp[i] = max(dp[i - 1] + v[i], psum[i] - psum[i - m]);
  }
  ll answer = *max_element(dp.begin(), dp.end());
  if(answer < 0) {
    cout << 0 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}