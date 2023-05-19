#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k, m, answer;
vector<ll> n_i, k_i, fact;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll temp = power(a, b / 2);
  if(b % 2) return temp * temp % m * a % m;
  else return temp * temp % m;
}

ll mod_inv(ll a) {
  return power(a, m - 2);
}

ll combination(ll n, ll r) {
  if(n < r) return 0;
  return fact[n] * mod_inv(fact[n - r] * fact[r] % m) % m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k >> m;

  fact.push_back(1);
  while(fact.size() <= m) {
    fact.push_back(fact.back() * fact.size() % m);
  }
  
  while(n) {
    n_i.push_back(n % m);
    n /= m;
  }

  while(k) {
    k_i.push_back(k % m);
    k /= m;
  }

  while(n_i.size() < k_i.size()) n_i.push_back(0);
  while(n_i.size() > k_i.size()) k_i.push_back(0);

  answer = 1;
  for(ll i = 0; i < n_i.size(); i++) {
    answer *= combination(n_i[i], k_i[i]);
    answer %= m;
  }

  cout << answer << '\n';


  
  return 0;
}