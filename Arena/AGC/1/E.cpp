#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9 + 7)
using ll = long long;
using namespace std;

ll n, k, a;
vector<vector<ll>> v;
vector<ll> p_of_two;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  p_of_two.push_back(1);
  while(p_of_two.size() < 200000) {
    p_of_two.push_back(p_of_two.back() * 2 % MOD);
  }
  
  cin >> n >> k;
  v.resize(k);
  for(ll i = 0; i < n; i++) {
    cin >> a;
    v[a % k].push_back(a);
  }
  
  ll answer = 1;
  answer *= (v[0].size() + 1);
  answer %= MOD;
  if(k % 2) {
    for(ll i = 1; i <= k / 2; i++) {
      answer *= ((p_of_two[v[i].size()] - 1) + (p_of_two[v[k - i].size()] - 1) + 1) % MOD;
      answer %= MOD;
    }
  } else {
    for(ll i = 1; i < k / 2; i++) {
      answer *= ((p_of_two[v[i].size()] - 1) + (p_of_two[v[k - i].size()] - 1) + 1) % MOD;
      answer %= MOD;
    }
    answer *= (v[k / 2].size() + 1);
    answer %= MOD;
  }

  answer = (answer - 1 - n + MOD) % MOD;
  cout << answer << '\n';
  
  return 0;
}