#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 1'000'000'000
typedef long long ll;
using namespace std;

vector<ll> dp;
ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  dp.resize(n + 1);
  dp[1] = 0;
  dp[2] = 1;
  for(ll i = 3; i <= n; i++) {
    dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    dp[i] %= MOD;
  }

  cout << dp[n] << '\n';
  
  return 0;
}