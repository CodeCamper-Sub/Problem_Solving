#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, s;
vector<pair<ll, ll>> v;
vector<ll> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> s;
  v.resize(n);
  dp.resize(n);
  for(auto& [h, c]: v) cin >> h >> c;
  sort(v.begin(), v.end());

  ll maxi = 0;
  ll k = 0;
  ll answer = 0;
  for(ll i = 0; i < v.size(); i++) {
    while(v[k].first + s <= v[i].first) {
      maxi = max(maxi, dp[k]);
      k++;
    }
    dp[i] = maxi + v[i].second;
    answer = max(answer, dp[i]);
  }

  cout << answer << '\n';

  
  return 0;
}