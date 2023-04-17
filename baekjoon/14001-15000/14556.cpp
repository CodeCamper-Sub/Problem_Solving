#include <bits/stdc++.h>
// #include <iostream>
#define INF 999999999999
#define MOD ll(1e9+9)
typedef long long ll;
using namespace std;

ll n;
vector<ll> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  dp.resize(n + 1);
  dp[0] = 1;
  for(ll i = 1; i <= n; i++) {
    dp[i] = (2 * (i - 1) + 1) * dp[i - 1] % MOD;
  }

  cout << dp[n] << '\n';
  
  return 0;
}