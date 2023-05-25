#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<ll> sieve;
vector<ll> primes;
ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;

  sieve.resize(10000000);
  for(ll i = 2; i * i * 12 <= n; i++) {
    if(sieve[i]) continue;
    primes.push_back(i);
    for(ll j = 2; i * i * j * j * 12 <= n; j++) {
      sieve[i * j] = i;
    }
  }

  ll answer = 0;
  for(ll i = 0; i < primes.size(); i++) {
    ll a = primes[i];
    for(ll j = i + 1; j < primes.size(); j++) {
      ll b = primes[j];
      for(ll k = j + 1; k < primes.size(); k++) {
        ll c = primes[k];
        if(a * a > n) break;
        else if(a * a * b > n) break;
        else if(a * a * b * c > n) break;
        else if(a * a * b * c * c <= n) {
          answer++;
        } else {
          break;
        }
      }
      if(a * a > n || a * a * b > n) break;
    }
  }

  cout << answer << '\n';
  
  return 0;
}