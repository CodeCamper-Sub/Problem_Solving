#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9 + 7)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<vector<ll>> dp;
vector<ll> memo;
ll n;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll tmp = power(a, b / 2) % MOD;
  if(b % 2) return tmp * tmp % MOD * a  % MOD;
  else return tmp * tmp % MOD;
}

ll mod_inv(ll a) {
  if(a <= 2 * n) {
    if(memo[a] != -1) return memo[a];
    else return memo[a] = power(a, MOD - 2) % MOD;
  } else {
    return power(a, MOD - 2) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  
  memo.assign(2 * n + 1, -1);
  dp.assign(2 * n + 1, vector<ll>(2 * n + 1));
  for(ll i = 2; i <= 2 * n; i += 2) {
    for(ll j = i; j >= 0; j--) {
      if(j >= i / 2) dp[i][j] = i / 2;
      else if(j > 0) {
        dp[i][j] = 0;
        dp[i][j] += j * mod_inv(i - j) % MOD * (1 + dp[i - 2][j - 1]) % MOD;
        dp[i][j] %= MOD;
        
        dp[i][j] += (i - 2 * j) * mod_inv(i - j) % MOD * j % MOD * mod_inv(i - j - 1) % MOD * (2 + dp[i - 2][j]) % MOD;
        dp[i][j] %= MOD;

        dp[i][j] += (i - 2 * j) * mod_inv(i - j) % MOD * (i - 2 * j - 2) % MOD * mod_inv(i - j - 1) % MOD * (1 + dp[i][j + 2]) % MOD;
        dp[i][j] %= MOD;

        dp[i][j] += (i - 2 * j) * mod_inv(i - j) % MOD * 1 * mod_inv(i - j - 1) % MOD * (1 + dp[i - 2][j]) % MOD;
        dp[i][j] %= MOD;
      }
      else {
        dp[i][j] = 0;
        dp[i][j] += 1 * mod_inv(i - 1) * (1 + dp[i - 2][0]) % MOD;
        dp[i][j] %= MOD;

        dp[i][j] += (i - 2) * mod_inv(i - 1) % MOD * (1 + dp[i][2]) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[2 * n][0] << '\n';
  
  return 0;
}