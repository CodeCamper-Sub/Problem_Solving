#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998'244'353
typedef long long ll;
using namespace std;

ll n, m, total, not_ambi;
vector<ll> sieve;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) { return power(a, MOD - 2); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve.resize(100'0010);
  for(ll i = 2; i < 100'0000; i++) {
    if(sieve[i]) continue;
    for(ll j = 2; i * j < 100'0000; j++) {
      sieve[i * j] = i;
    }
  }

  cin >> n >> m;
  ll k = m;
  k %= MOD;
  for(ll i = 0; i < n; i++) {
    total += k;
    total %= MOD;
    k *= (m % MOD);
    k %= MOD;
  }

  k = 1;
  ll now = 1;
  for(ll i = 1; i <= n; i++) {
    if(sieve[i] == 0) {
      k *= i;
      if(k > m) break;
    }
    now *= (m / k) % MOD;
    now %= MOD;
    not_ambi += now;
    not_ambi %= MOD;
  }

  cout << (total - not_ambi + MOD) % MOD << '\n';
  
  return 0;
}