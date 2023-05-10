#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
using Building = pair<ll, ll>;
vector<Building> v;
vector<ll> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  dp.assign(n, INF);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  dp[0] = abs(v[0].second) * 2;
  for(ll i = 1; i < n; i++) {
    ll side = abs(v[i].second) * 2;
    for(ll j = i; j >= 0; j--) {
      side = max(side, v[i].first - v[j].first);
      side = max(side, abs(v[j].second) * 2);
      if(j == 0) {
        dp[i] = min(dp[i], side);
      } else {
        dp[i] = min(dp[i], side + dp[j - 1]);
      }
    }
  }

  cout << dp[n - 1] << '\n';
  
  return 0;
}