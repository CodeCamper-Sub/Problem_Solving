#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll tt, n, fact[2002000], dp[1000001];

ll power(ll a, ll b) {
  if (b == 0)
    return 1;
  ll result = power(a, b / 2);
  if (b % 2) {
    return result * result % MOD * a % MOD;
  } else {
    return result * result % MOD;
  }
}

ll modulo_inverse(ll a) { return power(a, MOD - 2); }

ll combination(ll n, ll r) {
  return fact[n] * modulo_inverse(fact[n - r] * fact[r] % MOD) % MOD;
}

ll solve_with_combination(ll n) {
  return combination(2 * n, n) * modulo_inverse(n + 1) % MOD;
}

ll solve_with_dp(ll n) {
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (ll i = 1; i <= 2000000; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }

  dp[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    dp[i] = (long long)(dp[i - 1] * ((double)(4 * i - 2) / (i + 1)) + 0.5) % MOD;

  for(ll i = 1; i <= 100000; i++) {
    if(solve_with_combination(i) != solve_with_dp(i)) {
      cout << i << '\n';
    }
  }

  return 0;
}