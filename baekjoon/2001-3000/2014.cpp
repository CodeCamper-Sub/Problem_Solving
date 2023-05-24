#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll k, n, maxi;
vector<ll> primes;
set<ll> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> k >> n;
  primes.resize(k);
  for(ll i = 0; i < k; i++) {
    cin >> primes[i];
    s.insert(primes[i]);
  }

  while(--n) {
    ll now = *s.begin();
    s.erase(now);
    for(ll i = 0; i < k; i++) {
      if(s.size() >= n && *s.rbegin() < now * primes[i]) continue;
      if(now * primes[i] <= (1ll << 32)) {
        s.insert(now * primes[i]);
      }
    }
    maxi = max(maxi, ll(s.size()));
  }

  cout << *s.begin() << '\n';
  
  return 0;
}