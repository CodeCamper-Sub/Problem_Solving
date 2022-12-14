#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, x, y, cnt, divider;
ll sieve[10001000];
vector<ll> primes;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve[1] = -1;
  for(ll i = 2; i <= 10000000; i++) {
    if(sieve[i] == 0) {
      sieve[i] = -1;
      for(ll j = 2; i * j <= 10000000; j++) {
        sieve[i * j] = i;
      }
    }
  }

  cin >> tt;
  while(tt--) {
    cin >> x >> y;
    if(y - x == 1) {
      cout << -1 << '\n';
      continue;
    } else if (gcd(x, y) != 1) {
      cout << 0 << '\n';
      continue;
    }
    ll answer = INF;
    ll differ = y - x;
    primes = vector<ll>();
    while(sieve[differ] != -1) {
      primes.push_back(sieve[differ]);
      differ /= sieve[differ];
    }
    if(differ > 1) primes.push_back(differ);
    for(ll i = 0; i < primes.size(); i++) {
      answer = min(answer, primes[i] * ((x / primes[i]) + 1) - x);
    }
    cout << answer << '\n';
  }

  return 0;
}