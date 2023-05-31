#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> fact;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) {
  return power(a, MOD - 2);
}

ll combination(ll n, ll r) {
  return fact[n] * mod_inv(fact[n - r] * fact[r] % MOD) % MOD;
}

void init() {
  cin >> n >> k;
}

void solve() {
  cout << combination(n, k) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fact.push_back(1);
  while(fact.size() < 5000000) {
    fact.push_back(fact.back() * ll(fact.size()) % MOD);
  }

  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}