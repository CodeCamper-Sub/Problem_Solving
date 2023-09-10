#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<ll>> dp;
ll n, x, y, Q;
vector<pair<ll, ll>> buses;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> x >> y;
  buses.resize(n - 1);
  for(auto& [p, t]: buses) cin >> p >> t;
  buses.push_back({1, 0});



  ll divider = 1;
  for(ll i = 1; i <= 8; i++) divider = lcm(divider, i);
  
  dp.assign(divider, vector<ll>(n));

  for(ll i = 0; i < divider; i++) dp[i][n - 1] = y;

  for(ll i = n - 2; i >= 0; i--) {
    for(ll j = 0; j < divider; j++) {
      ll time_to_wait = (buses[i].first - (j % buses[i].first)) % buses[i].first;
      ll time_to_next = time_to_wait + buses[i].second;
      ll next_remainder = (j + time_to_next) % divider;
      dp[j][i] = time_to_next + dp[next_remainder][i + 1];
    }
  }

  cin >> Q;
  while(Q--) {
    ll q;
    cin >> q;

    ll time_to_start = q + x;
    ll start_remainder = time_to_start % divider;
    ll answer = q + x + dp[start_remainder][0];
    cout << answer << '\n';
  }
  
  return 0;
}