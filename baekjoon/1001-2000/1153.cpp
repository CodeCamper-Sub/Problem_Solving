#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> primes, sieve, goldbach;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  sieve.assign(1001000, -1);
  for(ll i = 2; i < 1001000; i++) {
    if(sieve[i] != -1) continue;
    primes.push_back(i);
    for(ll j = 2; i * j < 1001000; j++) {
      sieve[i * j] = i;
    }
  }
  goldbach.resize(1001000);
  ll maxi = -INF;
  for(ll i = 4; i < 1001000; i += 2) {
    for(ll prime: primes) {
      maxi = max(maxi, prime);
      if(sieve[i - prime] == -1) {
        goldbach[i] = prime;
        break;
      }
    }
  }

  cin >> n;

  if(n < 8) {
    cout << -1 << '\n';
  } else if(n % 2 == 0) {
    cout << 2 << ' ' << 2 << ' ' << goldbach[n - 4] << ' ' << n - 4 - goldbach[n - 4] << '\n';
  } else {
    cout << 2 << ' ' << 3 << ' ' << goldbach[n - 5] << ' ' << n - 5 - goldbach[n - 5] << '\n';
  }
  
  return 0;
}