#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, sum;
vector<ll> a;
vector<vector<ll>> dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  sum = 0;
  for(ll& a: a) {
    cin >> a;
    sum += a;
  }
  
  dp.assign(n + 1, vector<ll>(sum * 2 + 1, 0));
  dp[1][a[1] + sum] = 1;
  for(ll i = 1; i < n - 1; i++) {
    for(ll j = -sum; j <= sum; j++) {
      if(dp[i][j + sum] == 0) continue;
      dp[i + 1][a[i + 1] + j + sum] += dp[i][j + sum];
      dp[i + 1][a[i + 1] + j + sum] %= MOD;
      if(j) {
        dp[i + 1][a[i + 1] - j + sum] += dp[i][j + sum];
        dp[i + 1][a[i + 1] - j + sum] %= MOD;
      }
    }
  }
  ll answer = 0;
  for(ll i = -sum; i <= sum; i++) {
    answer += dp[n - 1][i + sum];
    answer %= MOD;
  }

  cout << answer << '\n';

  
  return 0;
}