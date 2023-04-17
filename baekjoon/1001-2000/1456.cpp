#include <bits/stdc++.h>
#define INF 999999999999
typedef __int128_t ll;
using namespace std;

ll sieve[10101010], A, B;
vector<ll> primes, candidates;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 2; i < 10101010; i++) {
    if(sieve[i] != 0) continue;
    primes.push_back(i);
    for(ll j = 1; i * j < 10101010; j++) {
      sieve[i * j] = 1;
    }
  }

  for(ll prime: primes) {
    ll k = prime * prime;
    while(k <= 10e14) {
      candidates.push_back(k);
      k *= prime;
    }
  }

  sort(candidates.begin(), candidates.end());

  long long a, b;
  cin >> a >> b;
  A = a;
  B = b;
  auto l = lower_bound(candidates.begin(), candidates.end(), A);
  auto r = upper_bound(candidates.begin(), candidates.end(), B);

  cout << r - l << '\n';
  
  return 0;
}