#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 998244353
typedef long long ll;
using namespace std;

ll n, answer, products;
vector<ll> a, sieve, fact, cnt;
vector<vector<ll>> dp; 
// {i번째 소수까지 소수를 j개 선택했을 때 분모들의 합} dp(x, y) = dp(x + 1, y + 1) / (primes[x].second - 1)! + dp(x + 1, y) / (primes[x].second)!
vector<pair<ll, ll>> primes;
map<ll, ll> inv;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll a) {
  if(inv.count(a)) return inv[a];
  return inv[a] = power(a, MOD - 2) % MOD;
}

ll divide_conquer(ll x, ll y) {
  if(dp[x][y] != -1) return dp[x][y];
  if(primes.size() - x + y < n) return dp[x][y] = 0;
  if(x == primes.size()) return dp[x][y] = y < n ? 0 : 1;
  if(y < n) {
    dp[x][y] = divide_conquer(x + 1, y + 1) * mod_inv(fact[primes[x].second - 1]) + divide_conquer(x + 1, y) * mod_inv(fact[primes[x].second]);
  } else {
    dp[x][y] = divide_conquer(x + 1, y) * mod_inv(fact[primes[x].second]);
  }
  dp[x][y] %= MOD;
  return dp[x][y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  sieve.assign(1001000, -1);
  sieve[1] = 1;
  for(ll i = 2; i < 1001000; i++) {
    if(sieve[i] != -1) continue;
    for(ll j = 2; i * j < 1001000; j++) {
      sieve[i * j] = i;
    }
  }
  fact.push_back(1);
  for(ll i = 1; i <= 3000; i++){
    fact.push_back(fact.back() * i % MOD);
  }

  cin >> n;
  a.resize(n * 2);
  for(ll &a: a) { 
    cin >> a;
  }
  
  cnt.assign(*max_element(a.begin(), a.end()) + 1, 0);
  for(ll i = 0; i < 2 * n; i++) {
    cnt[a[i]]++;
  }

  ll sum = 0;
  for(ll i = 2; i < cnt.size(); i++) {
    if(sieve[i] != -1 || cnt[i] == 0) continue;
    primes.push_back({i, cnt[i]});
    sum++;
  }

  if(sum < n) {
    cout << 0 << '\n';
    return 0;
  }

  products = fact[n];
  for(ll i = 2; i < cnt.size(); i++) {
    if(sieve[i] == -1 || cnt[i] <= 1) continue;
    products *= mod_inv(fact[cnt[i]]);
    products %= MOD;
  }

  dp.assign(primes.size() + 1, vector<ll>(n + 1, -1));
  cout << products * divide_conquer(0, 0) % MOD << '\n';

  
  return 0;
}