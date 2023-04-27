#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MAX ll(1e7 + 10)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, sieve;
map<ll, ll> factors;

void init() {
  cin >> n;
  a.resize(n);
  factors.clear();
  for(ll& a: a) cin >> a;
}

void factorize(ll n) {
  while(sieve[n] != -1) {
    factors[sieve[n]]++;
    n /= sieve[n];
  }
  factors[n]++;
}

void solve() {
  for(ll i = 0; i < n; i++) {
    factorize(a[i]);
  }
  ll answer = 0;
  ll remainders = 0;
  for(auto& [k, v]: factors) {
    answer += v / 2;
    remainders += v % 2;
  }
  answer += remainders / 3;
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve.assign(MAX, -1);
  for(ll i = 2; i < MAX; i++) {
    if(sieve[i] != -1) continue;
    for(ll j = 2; i * j < MAX; j++) {
      sieve[i * j] = i;
    }
  }

  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}