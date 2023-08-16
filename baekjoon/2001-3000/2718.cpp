#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<ll> dp(30);
ll t, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  dp[0] = 1;
  dp[1] = 1;
  for(ll i = 2; true; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] * 4;
    for(ll j = 2; i - 2 * j >= 0; j++) {
      dp[i] += dp[i - 2 * j] * 3;
    }
    for(ll j = 2; i - 2 * j + 1 >= 0; j++) {
      dp[i] += dp[i - 2 * j + 1] * 2;
    }
    if(dp[i] >= ll(1e10)) break;
  }

  cin >> t;
  while(t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  
  return 0;
}