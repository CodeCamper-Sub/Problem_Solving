#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll n, m, p;
vector<ll> fact;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % MOD * a % MOD;
  else return temp * temp % MOD;
}

ll solve(ll n, ll m, ll p) {
  ll answer = 1;
  if(n == m) {
    if(m == p) {
      for(ll i = n; i > 0; i--) {
        answer *= i;
        answer %= MOD;
      }
      return answer;
    } else {
      return 0;
    }
  }
  for(ll i = n; i > n - m - 1; i--) {
    answer *= i;
    answer %= MOD;
  }
  answer = answer * power(n - m, p - m - 1) % MOD;
  return answer;
}

ll mod_inv(ll a) {
  return power(a, MOD - 2) % MOD;
}

ll combination(ll n, ll r) {
  return fact[n] * mod_inv(fact[n - r] * fact[r] % MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fact.push_back(1);
  while(fact.size() < 150) {
    fact.push_back(fact.back() * ll(fact.size()) % MOD); 
  }
  
  cin >> n >> m >> p;
  ll answer = 0;
  for(ll i = 0; i < n; i++) {
    if(i % 2 == 0) {
      answer += combination(n, i) * solve(n - i, m, p) % MOD;
    } else {
      answer -= combination(n, i) * solve(n - i, m, p) % MOD;
    }
    answer = (answer + MOD) % MOD;
  }

  cout << answer << '\n';
  
  return 0;
}