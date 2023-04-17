#include <bits/stdc++.h>
#define INF 999999999999
#define MOD ll(1e4+7)
typedef long long ll;
using namespace std;

ll n, fact[100];

ll pow(ll a, ll b) {
  if(b == 0) return 1;
  else if(b == 1) return a;
  ll temp = pow(a, b / 2);
  if(b % 2) return temp * temp % MOD * a  % MOD;
  else return temp * temp % MOD;
}

ll mod_inv(ll n) {
  return pow(n, MOD - 2);
}

ll combination(ll n, ll r) {
  return fact[n] * mod_inv(fact[n-r] * fact[r] % MOD) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fact[0] = 1;
  for(ll i = 1; i < 100; i++) fact[i] = fact[i - 1] * i % MOD;

  cin >> n;
  
  ll answer = 0;
  for(ll i = 1; i <= 13 && 4 * i <= n; i++) {
    if(i % 2) {
      answer += combination(13, i) * combination(52 - 4 * i, n - 4 * i) % MOD;
      answer %= MOD;
    } else {
      answer -= combination(13, i) * combination(52 - 4 * i, n - 4 * i) % MOD; 
      answer = (answer + MOD) % MOD;
    }
  }

  cout << answer << '\n';
  
  return 0;
}