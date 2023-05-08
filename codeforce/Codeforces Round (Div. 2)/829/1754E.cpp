#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, cnt, o;
vector<ll> a, dp;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) {
  return power(a, MOD - 2) % MOD;
}

void init() {
  cin >> n;
  a.resize(n);
  cnt = 0;
  for(ll& a: a) {
    cin >> a;
    if(!a) cnt++;
  }
  dp.resize(cnt + 1);
  o = 0;
  for(ll i = 0; i < n; i++) {
    if(i < cnt && a[i] == 0) o++;
  }
}

void solve() {
  dp[cnt] = 0;
  for(ll i = cnt - 1; i >= 0; i--) {
    ll dividend = 2 * (cnt - i) * (cnt - i) % MOD;
    ll divider = n * (n - 1) % MOD;
    dp[i] = dp[i + 1] + divider * mod_inv(dividend) % MOD;
    dp[i] %= MOD;
  }
  cout << dp[o] << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}